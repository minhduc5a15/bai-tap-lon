#include "common.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_GAME);
    SetTargetFPS(FPS);
    backgroundImageInit();
    createDatabase();

    while (!WindowShouldClose()) {
        BeginDrawing();
        setCurrLevel(getCurrLevel());
        setAnswers(getCurrLevel());
        getCurrentQuest(getCurrLevel());
        setRunning(); // true
        printf("current level: %d\n", getCurrLevel());
        {
            setBackgroundImage();
            drawQuestion();
            drawAnswers();
        }
        onEvents();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
