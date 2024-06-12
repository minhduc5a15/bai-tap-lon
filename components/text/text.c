#include "text.h"

static int *CodepointRemoveDuplicates(int *codepoints, int codepointCount, int *codepointsResultCount);

void UnicodeTextInit(UnicodeText *unicodeText, const char *fontDirectory, char *value) {
    unicodeText->fontDirectory = strdup(fontDirectory);
    unicodeText->value = value;
    unicodeText->codepointCount = 0;
    unicodeText->codepoints = LoadCodepoints(value, &unicodeText->codepointCount);
    unicodeText->codepointsNoDups = CodepointRemoveDuplicates(unicodeText->codepoints, unicodeText->codepointCount, &unicodeText->codepointsNoDupsCount);
    Font temp = LoadFont(fontDirectory);
    unicodeText->font = LoadFontEx(fontDirectory, temp.baseSize, unicodeText->codepoints, unicodeText->codepointCount);
    UnloadCodepoints(unicodeText->codepoints);
    free(unicodeText->codepointsNoDups);
}

void DrawUnicodeText(UnicodeText unicodeText, Vector2 postion, float fontSize, float spacing, Color color) {
    DrawTextEx(unicodeText.font, TextFormat(unicodeText.value), postion, fontSize, spacing, color);
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