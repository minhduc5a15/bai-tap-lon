#include "game/game.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_LOGIN);
    SetTargetFPS(FPS);

    BackgroundImageInit();

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            setBackgroundImage();
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
