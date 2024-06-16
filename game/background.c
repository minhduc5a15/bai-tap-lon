#include "game.h"

Container bgContainer;

void backgroundImageInit(void) {
    Image bgImage = LoadImage(BACKGROUND_IMAGE);
    Rectangle destRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    containerInit(&bgContainer, bgImage, bgImage, destRect, (V2){0, 0});
}

void drawBackgroundImage(void) {
    DrawContainer(bgContainer, 0, WHITE);
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color) {0, 0, 0, 155});
}