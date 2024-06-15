#include "common.h"

int main() {
    SetTraceLogLevel(LOG_NONE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_GAME);
    SetTargetFPS(FPS);
    backgroundImageInit();
    createDatabase();
    UnicodeText text = newUnicodeText(DEFAULT_FONT_DIR, "YOU WIN");
    setCurrLevel(LEVEL_1);
    while (!WindowShouldClose()) {
        if (!getPassed() && getCurrLevel() <= 15) {
            setPassed(true);
            setAnswers(getCurrLevel());
            getCurrentQuest(getCurrLevel());
        }
        BeginDrawing();
        {
            if (currLevel <= LEVEL_15) {
                setBackgroundImage();
                drawQuestion();
                drawAnswers();
                onEvents();
            }
            else {
                DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
                DrawUnicodeText(text, (V2){300, 300}, 32, 2, WHITE);
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
