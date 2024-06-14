#include "common.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_GAME);
    SetTargetFPS(FPS);
    backgroundImageInit();
    createDatabase();
    getCurrentQuest(1);
    setAnswers();
    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            setBackgroundImage();
            drawQuestion();
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
