#include "level.h"

static char levelStr[3];

void setLevelContainer(int level) {
    Image img = LoadImage(CURRENT_LEVEL_BG);
    Rectangle destRect = {300, 300, img.width / 2, img.height};
    LevelContainer = newContainer(img, img, destRect, (V2){});
    sprintf(levelStr, "%d", level);
    LevelValue = newUnicodeText(DEFAULT_FONT, levelStr);
}

void DrawLevelContainer() {
    DrawContainer(LevelContainer, 0, WHITE);
    DrawUnicodeText(LevelValue, (V2){100, 100}, 32, 0, WHITE);
}