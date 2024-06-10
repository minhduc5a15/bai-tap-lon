#include "constants/constants.h"
#include "components/headers.h"

Input username_input;
Font username_font;

const int username_input_width = 400;
const int username_input_height = 50;
const int username_input_font_size = 24;
const int buttonRect_width = 300;
const int buttonRect_height = 90;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_LOGIN);
    SetTargetFPS(FPS);
    username_font = LoadFont("D:/code/Repositories/raylib_project/font/Roboto-Medium.ttf");
    inputInit(&username_input, username_font, "username", username_input_width, username_input_height, SCREEN_WIDTH / 2 - username_input_width / 2, SCREEN_HEIGHT / 2 - username_input_height / 2, username_input_font_size);

    // Background-image
    Texture2D background_image = LoadTexture(BACKGROUND_IMAGE_DIR);
    Rectangle sourceRec = {0.0f, 0.0f, (float) background_image.width, (float) background_image.height};
    Rectangle destRec = {0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT};
    Vector2 origin = {0.0f, 0.0f};
    // draw button
    Rectangle buttonRect = {SCREEN_WIDTH / 2 - buttonRect_width / 2, SCREEN_HEIGHT / 2 - buttonRect_height / 2, buttonRect_width, buttonRect_height};
    int radius = 15;
    Button button = {buttonRect, "click me", username_font, BLUE, WHITE};
    setOpacity(&button, 0.9);
    printf("111%c\n", button.backgroundColor.a);
    while (!WindowShouldClose()) {
//        onChange(&username_input);
        BeginDrawing();
        {
//            DrawInput(username_input);
            {
                DrawTexturePro(background_image, sourceRec, destRec, origin, 0.0f, WHITE);
                DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color) {0, 0, 0, 128});
            }
//            DrawRectWithBorderRadius(buttonRect, radius, BLUE);
            DrawButton(button, radius);
            onClick(button, Hello);
            onHover(button);
        }
        EndDrawing();
    }
    CloseWindow();
    free(username_input.placeHolder);
    free(username_input.value);
    return 0;
}
