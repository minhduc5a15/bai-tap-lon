#include "text.h"

__attribute__((unused)) void UnicodeTextInit(UnicodeText *unicodeText, const char *fontDirectory, char *value) {
    unicodeText->fontDirectory = strdup(fontDirectory);
    unicodeText->text = strdup(addStr(value, " "));
    unicodeText->codepointCount = 0;
    unicodeText->codepoints = LoadCodepoints(value, &unicodeText->codepointCount);
    Font temp = LoadFont(fontDirectory);
    unicodeText->font = LoadFontEx(fontDirectory, temp.baseSize, unicodeText->codepoints, unicodeText->codepointCount + 1);
    UnloadCodepoints(unicodeText->codepoints);
    SetTextureFilter(unicodeText->font.texture, TEXTURE_FILTER_TRILINEAR);
    return;
}

UnicodeText newUnicodeText(const char *fontDirectory, char *value) {
    UnicodeText result;
    result.fontDirectory = strdup(fontDirectory);
    result.text = strdup(addStr(value, " "));
    result.codepointCount = 0;
    result.codepoints = LoadCodepoints(value, &result.codepointCount);
    Font temp = LoadFont(fontDirectory);
    result.font = LoadFontEx(fontDirectory, temp.baseSize, result.codepoints, result.codepointCount + 5);
    UnloadCodepoints(result.codepoints);
    SetTextureFilter(result.font.texture, TEXTURE_FILTER_TRILINEAR);
    return result;
}

void DrawUnicodeText(UnicodeText unicodeText, Vector2 position, float fontSize, float spacing, Color color) {
    DrawTextEx(unicodeText.font, TextFormat(unicodeText.text), position, fontSize, spacing, color);
}
