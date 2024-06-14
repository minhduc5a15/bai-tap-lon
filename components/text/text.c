#include "text.h"

static int *CodepointRemoveDuplicates(int *codepoints, int codepointCount, int *codepointsResultCount);

static char **WrapText(Font font, const char *text, float fontSize, float maxWidth, int *lineCount);

void UnicodeTextInit(UnicodeText *unicodeText, const char *fontDirectory, char *value) {
    unicodeText->fontDirectory = strdup(fontDirectory);
    unicodeText->value = strdup(TextFormat(value));
    unicodeText->codepointCount = 0;
    unicodeText->codepoints = LoadCodepoints(value, &unicodeText->codepointCount);
    unicodeText->codepointsNoDups = CodepointRemoveDuplicates(unicodeText->codepoints, unicodeText->codepointCount, &unicodeText->codepointsNoDupsCount);
    Font temp = LoadFont(fontDirectory);
    unicodeText->font = LoadFontEx(fontDirectory, temp.baseSize, unicodeText->codepoints, unicodeText->codepointCount);
    UnloadCodepoints(unicodeText->codepoints);
    free(unicodeText->codepointsNoDups);
    SetTextureFilter(unicodeText->font.texture, TEXTURE_FILTER_TRILINEAR);
    return;
}

UnicodeText newUnicodeText(const char *fontDirectory, char *value) {
    UnicodeText result;
    result.fontDirectory = strdup(fontDirectory);
    result.value = strdup(TextFormat(value));
    result.codepointCount = 0;
    result.codepoints = LoadCodepoints(value, &result.codepointCount);
    result.codepointsNoDups = CodepointRemoveDuplicates(result.codepoints, result.codepointCount, &result.codepointsNoDupsCount);
    Font temp = LoadFont(fontDirectory);
    result.font = LoadFontEx(fontDirectory, temp.baseSize, result.codepoints, result.codepointCount);
    UnloadCodepoints(result.codepoints);
    free(result.codepointsNoDups);
    SetTextureFilter(result.font.texture, TEXTURE_FILTER_TRILINEAR);
    return result;
}

void DrawUnicodeText(UnicodeText unicodeText, Vector2 position, float fontSize, float spacing, Color color) {
    DrawTextEx(unicodeText.font, TextFormat(unicodeText.value), position, fontSize, spacing, color);
}

static int *CodepointRemoveDuplicates(int *codepoints, int codepointCount, int *codepointsResultCount) {
    int codepointsNoDupsCount = codepointCount;
    int *codepointsNoDups = (int *) calloc(codepointCount, sizeof(int));
    memcpy(codepointsNoDups, codepoints, codepointCount * sizeof(int));

    for (int i = 0; i < codepointsNoDupsCount; ++i) {
        for (int j = i + 1; j < codepointsNoDupsCount; ++j) {
            if (codepointsNoDups[i] == codepointsNoDups[j]) {
                for (int k = j; k < codepointsNoDupsCount; ++k) {
                    codepointsNoDups[k] = codepointsNoDups[k + 1];
                }
                codepointsNoDupsCount--;
                j--;
            }
        }
    }

    *codepointsResultCount = codepointsNoDupsCount;
    return codepointsNoDups;
}

static char **WrapText(Font font, const char *text, float fontSize, float maxWidth, int *lineCount) {
    int len = strlen(text);
    char **lines = (char **) malloc(sizeof(char *) * len); // Cấp phát đủ bộ nhớ cho từng dòng
    int currentLine = 0;
    char *line = (char *) malloc(len + 1);
    int lineLen = 0;
    float lineWidth = 0;

    for (int i = 0; i < len; i++) {
        char c = text[i];
        char nextChar = (i < len - 1) ? text[i + 1] : '\0';

        // Đo chiều rộng của ký tự hiện tại
        int advance = MeasureTextEx(font, &c, 1, fontSize).x;
        lineWidth += advance;

        if (lineWidth > maxWidth || c == '\n') {
            if (c == '\n') {
                i++;
            }
            line[lineLen] = '\0';
            lines[currentLine] = strdup(line);
            currentLine++;
            lineLen = 0;
            lineWidth = 0;
        }

        if (c != '\n') {
            line[lineLen++] = c;
        }
    }

    line[lineLen] = '\0';
    lines[currentLine] = strdup(line);
    currentLine++;

    free(line);
    *lineCount = currentLine;
    return lines;
}