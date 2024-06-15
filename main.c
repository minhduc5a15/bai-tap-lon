#include "common.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_GAME);
    SetTargetFPS(FPS);
    backgroundImageInit();
    createDatabase();
    setCurrLevel(1);
    setAnswers(getCurrLevel());
    getCurrentQuest(LEVEL_1);
    int *passed = (int *) calloc(16, sizeof(int));
    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            setBackgroundImage();
            drawQuestion();
            drawAnswers();
        }
        EndDrawing();
    }
    free(passed);
    CloseWindow();
    return 0;
}
