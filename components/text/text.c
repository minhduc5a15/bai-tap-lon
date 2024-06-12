#include "text.h"

static int *CodepointRemoveDuplicates(int *codepoints, int codepointCount, int *codepointsResultCount);

void UnicodeTextInit(UnicodeText *unicodeText, Font font, char *text) {
    unicodeText->font = font;
    unicodeText->text = text;
    unicodeText->codepointCount = 0;
    unicodeText->codepoints = LoadCodepoints(text, &unicodeText->codepointCount);
    unicodeText->codepointsNoDups = 0;
    UnloadCodepoints(unicodeText->codepoints);
}

void DrawUnicodeText(UnicodeText unicodeText, V2 postion, float fontSize, float spacing, Color color) {
    DrawTextEx(unicodeText.font, unicodeText.text, postion, fontSize, spacing, color);
}

static int *CodepointRemoveDuplicates(int *codepoints, int codepointCount, int *codepointsResultCount) {
    int codepointsNoDupsCount = codepointCount;
    int *codepointsNoDups = (int *) calloc(codepointCount, sizeof(int));
    memcpy(codepointsNoDups, codepoints, codepointCount * sizeof(int));

    for (int i = 0; i < codepointsNoDupsCount; i++) {
        for (int j = i + 1; j < codepointsNoDupsCount; j++) {
            if (codepointsNoDups[i] == codepointsNoDups[j]) {
                for (int k = j; k < codepointsNoDupsCount; k++) codepointsNoDups[k] = codepointsNoDups[k + 1];

                codepointsNoDupsCount--;
                j--;
            }
        }
    }

    *codepointsResultCount = codepointsNoDupsCount;
    return codepointsNoDups;
}