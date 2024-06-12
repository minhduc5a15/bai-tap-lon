#ifndef TEXT_H
#define TEXT_H
#include <raylib.h>
#include <stdlib.h>
#include <string.h>

struct UnicodeText {
    Font font;
    char *fontDirectory;
    char *text;
    int codepointCount;
    int *codepoints;
    int *codepointsNoDups;
    int codepointsNoDupsCount;
};

typedef struct UnicodeText UnicodeText;

void UnicodeTextInit(UnicodeText *unicodeText, char *fontDirectory, char *text);

void DrawUnicodeText(UnicodeText unicodeText, Vector2 postion, float fontSize, float spacing, Color color);
#endif