#include "constants/constants.h"
#include "components/components.h"

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "window");
    SetTargetFPS(60);
    UnicodeText text;
    UnicodeTextInit(&text, "D:/code/Repositories/raylib_project/font/Roboto-Bold.ttf", "Đức đẹp trai");
    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);
            DrawUnicodeText(text, (V2) {200, 200}, 42, 5, WHITE);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}