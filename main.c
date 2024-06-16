#include "common.h"

int main() {
    SetTraceLogLevel(LOG_NONE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_GAME);
    SetTargetFPS(FPS);
    backgroundImageInit();
    createDatabase();
    UnicodeText text = newUnicodeText(DEFAULT_FONT, "YOU WIN");
    UnicodeText lose = newUnicodeText(DEFAULT_FONT, "YOU LOSE");
    setCurrLevel(LEVEL_1);
    while (!WindowShouldClose()) {
        if (!getPassed() && getCurrLevel() <= 15) {
            setPassed(true);
            setAnswers(getCurrLevel());
            getCurrentQuest(getCurrLevel());
            setLevelContainer(getCurrLevel());
            setRewardContainer(getCurrLevel());
        }
        BeginDrawing();
        {
            if (currLevel <= LEVEL_15) {
                if (getRunning()) {
                    drawBackgroundImage();
                    drawQuestion();
                    drawAnswers();
                    onEvents();
                    drawRewardContainer();
                }
                else {
                    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
                    DrawUnicodeText(lose, (V2) {300, 300}, 32, 2, WHITE);
                }
            }
            else {
                DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
                DrawUnicodeText(text, (V2) {300, 300}, 32, 2, WHITE);
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
