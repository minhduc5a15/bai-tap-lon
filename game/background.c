#include "game.h"

Container bgContainer;

void backgroundImageInit(void) {
    Image bgImage = LoadImage(BACKGROUND_IMAGE_DIR);
    Rectangle destRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    V2 origin = {0, 0};
    ContainerInit(&bgContainer, bgImage, destRect, origin);
}

void setBackgroundImage(void) {
    DrawContainer(bgContainer, 0, WHITE);
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color) {0, 0, 0, 128});
}