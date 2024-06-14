#ifndef TEXT_H
#define TEXT_H

#include "../common.h"

struct UnicodeText {
    Font font;
    char *fontDirectory;
    char *value;
    int codepointCount;
    int *codepoints;
    int *codepointsNoDups;
    int codepointsNoDupsCount;
};

typedef struct UnicodeText UnicodeText;

void UnicodeTextInit(UnicodeText *unicodeText, const char *fontDirectory, char *value);

UnicodeText newUnicodeText(const char *fontDirectory, char *value);

void DrawUnicodeText(UnicodeText unicodeText, Vector2 position, float fontSize, float spacing, Color color);

#endif