#include "start.h"

static UnicodeText text;
static const int width = 300;
static const int height = 75;
static Container background;

void startGame() {
    auto img = LoadImage(START_BACKGROUND);
    Rectangle destRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    background = newContainer(img, img, destRect, (V2) {});
    text = newUnicodeText(DEFAULT_FONT, "Bắt đầu ");
    img = LoadImage(START_BUTTON);
    destRect = (Rectangle) {SCREEN_WIDTH / 2 - width / 2, SCREEN_HEIGHT / 2 - height / 2, width, height};
    startButton = newContainer(img, img, destRect, (V2) {});
}

void onClickStartButton(Callback callback) {
    if (isClicked() && CheckCollisionPointRec(mousePos, startButton.destRect)) {
        callback();
        return;
    }
}

void onHoverStartButton() {
    if (CheckCollisionPointRec(mousePos, startButton.destRect)) {
        currentHoverRect = &startButton.destRect;
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else currentHoverRect = nullptr;
}

void drawStartWindow() {
    if (!getStarted()) {
        DrawContainer(background, 0, WHITE);
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, setOpacity(BLACK, 0.5));
        DrawContainer(startButton, 0, WHITE);
        DrawUnicodeText(text, getCenter(startButton.destRect, MeasureTextEx(text.font, text.text, 30, 0)), 30, 0, WHITE);
    }
}