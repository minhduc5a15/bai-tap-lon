#include "button.h"

// Hàm khởi tạo một button với các chỉ số cho trước
void ButtonInit(Button *button, float x, float y, float width, float height, const char *value, Font buttonFont, Color backgroundColor, Color textColor) {
    button->rect = (Rectangle) {x, y, width, height};
    button->value = (char *) malloc((strlen(value) + 1) * sizeof(char));
    strcpy(button->value, value);
    button->backgroundColor = backgroundColor;
    button->textColor = textColor;
    button->font = buttonFont;
}

// Hàm khởi tạo một button với rect cho trước
void ButtonInitWithRect(Button *button, Rectangle rect, const char *value, Font buttonFont, Color backgroundColor, Color textColor) {
    button->rect = rect;
    button->value = (char *) malloc((strlen(value) + 1) * sizeof(char));
    strcpy(button->value, value);
    button->backgroundColor = backgroundColor;
    button->textColor = textColor;
    button->font = buttonFont;
}

void DrawButton(const Button button, int radius) {
    DrawRectWithBorderRadius(button.rect, radius, button.backgroundColor);
    // Tính toán kích thước của văn bản
    Vector2 textSize = MeasureTextEx(button.font, button.value, button.font.baseSize, 1);

    // Tính toán vị trí để văn bản nằm ngay giữa nút
    float textX = button.rect.x + button.rect.width / 2 - textSize.x / 2;
    float textY = button.rect.y + button.rect.height / 2 - textSize.y / 2;

    // Vẽ văn bản
    DrawTextEx(button.font, button.value, (Vector2) {textX, textY}, button.font.baseSize, 1, button.textColor);
}

void Hello() {
    printf("Hello World\n");
}

void onClick(Button button, Callback callback) {
    if (isClicked() && CheckCollisionPointRec(mousePos, button.rect)) {
        callback();
    }
}

void onHover(Button button) {
    if (CheckCollisionPointRec(mousePos, button.rect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        return;
    }
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

