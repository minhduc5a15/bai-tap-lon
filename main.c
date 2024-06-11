#include "constants/constants.h"
#include "components/headers.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_LOGIN);
    SetTargetFPS(FPS);
    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color) {0, 0, 0, 128});
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
