#include "../common.h"

struct UnicodeText {
    Font font;
    char *text;
    int codepointCount;
    int *codepoints;
    int *codepointsNoDups;
};

typedef struct UnicodeText UnicodeText;

void UnicodeTextInit(UnicodeText *unicodeText, Font font, char *text);

void DrawUnicodeText(UnicodeText unicodeText, V2 postion, float fontSize, float spacing, Color color);