#include "input.h"
#include <string.h>
#include <stdlib.h>

// Hàm khởi tạo cho thanh input
void inputInit(Input *input, Font font, const char *place_holder, int width, int height, int x, int y, int fontSize) {
    // Cấp phát bộ nhớ cho placeHolder
    input->placeHolder = (char *) malloc((strlen(place_holder) + 1) * sizeof(char));
    strcpy(input->placeHolder, place_holder);
    input->x = x;
    input->y = y;
    input->maxLength = 25; /* default font size */
    input->value = (char *) malloc(input->maxLength * sizeof(char));
    input->width = width;
    input->height = height;
    input->font = font;
    input->isMouseEnter = false;
    input->textBox = (Rectangle) {x, y, width, height};
    input->currentLength = 0;
    input->fontSize = fontSize;
}

//
bool checkValidKey(int key, int curr_length, const int max_length) {
    if ((key >= 32) && (key <= 125) && (curr_length <= max_length)) {
        return true;
    }
    return false;
}

// hàm vẽ thanh input
void onChange(Input *input) {
    // Kiểm tra xem người dùng có di chuyển chuột vào thành username_input hay không
    if (CheckCollisionPointRec(GetMousePosition(), input->textBox)) {
        input->isMouseEnter = true;
    }
    else {
        input->isMouseEnter = false;
    }

    if (input->isMouseEnter) {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = GetCharPressed();
        while (key > 0) {
            if (checkValidKey(key, input->currentLength, input->maxLength)) {
                if (checkValidKey(key, input->currentLength, input->maxLength)) {
                    input->value[input->currentLength] = (char) (key);
                    input->value[++input->currentLength] = '\0';
                }
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            --input->currentLength;
            input->currentLength = max(input->currentLength, 0);
            input->value[input->currentLength] = '\0';
        }
    }
    else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void DrawInput(Input input) {
    DrawRectangleRec(input.textBox, WHITE);

    if (input.isMouseEnter) DrawRectangleLines(input.x, input.y, input.width, input.height, GRAY);
    else DrawRectangleLines(input.x, input.y, input.width, input.height, BLACK);

//    DrawText(input.currentLength > 0 ? input.value : input.placeHolder, input.x + 5, SCREEN_HEIGHT / 2 - input.y / 2 - input.fontSize, input.fontSize, MAROON);
//    DrawText(input.currentLength > 0 ? input.value : input.placeHolder, SCREEN_WIDTH / 2 - input.width / 2 + 5, SCREEN_HEIGHT / 2 - input.height / 2 + input.fontSize / 2, input.fontSize, GRAY);
    DrawTextEx(input.font, input.currentLength > 0 ? input.value : input.placeHolder, (Vector2) {SCREEN_WIDTH / 2 - input.width / 2 + 5, SCREEN_HEIGHT / 2 - input.height / 2 + input.fontSize / 2}, input.fontSize, 1, GRAY);
    if (input.isMouseEnter) {
//        if (input.currentLength < input.maxLength) {
//            printf("%d %d\n", max(MeasureText(input.value, input.fontSize), 0), input.currentLength);
        DrawText("|", SCREEN_WIDTH / 2 - input.width / 2 + MeasureTextEx(input.font, input.value, input.fontSize, 1).x + INPUT_PADDING_LEFT, SCREEN_HEIGHT / 2 - input.height / 2 + input.fontSize / 2, 25, BLACK);
//        }
    }
}