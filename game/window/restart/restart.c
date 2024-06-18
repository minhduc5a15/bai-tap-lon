#include "restart.h"


static UnicodeText text;
static const int width = 300;
static const int height = 75;
static V2 currMeasureText;

void endGame() {
    text = newUnicodeText(DEFAULT_FONT, "Chơi lại");
    auto img = LoadImage(START_BUTTON);
    Rectangle destRect = {SCREEN_WIDTH / 2 - width / 2, SCREEN_HEIGHT / 2 - height / 2, width, height};
    restartButton = newContainer(img, img, destRect, (V2) {});
    currMeasureText = MeasureTextEx(text.font, text.text, 34, 0);
}

void drawEndgameWindow() {
//    if (getEndgame()) {
    DrawContainer(restartButton, 0, WHITE);
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, setOpacity(BLACK, 0.5));

    DrawUnicodeText(text, getCenter(restartButton.destRect, currMeasureText), 34, 0, WHITE);
//    }
}

void onClickRestartButton(Callback callback) {
    if (isClicked() && CheckCollisionPointRec(mousePos, restartButton.destRect)) {
        callback();
        return;
    }
}

