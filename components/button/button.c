#include "button.h"

// Hàm khởi tạo một button với các chỉ số cho trước
__attribute__((unused)) void ButtonInit(Button *button, float x, float y, float width, float height, const char *value, Font buttonFont, Color backgroundColor, Color textColor) {
    button->rect = (Rectangle) {x, y, width, height};
    button->value = (char *) malloc((strlen(value) + 1) * sizeof(char));
    strcpy(button->value, value);
    button->backgroundColor = backgroundColor;
    button->textColor = textColor;
    button->font = buttonFont;
}

// Hàm khởi tạo một button với rect cho trước
__attribute__((unused)) void ButtonInitWithRect(Button *button, Rectangle rect, const char *value, Font buttonFont, Color backgroundColor, Color textColor) {
    button->rect = rect;
    button->value = (char *) malloc((strlen(value) + 1) * sizeof(char));
    strcpy(button->value, value);
    button->backgroundColor = backgroundColor;
    button->textColor = textColor;
    button->font = buttonFont;
}

__attribute__((unused)) void setOpacity(Button *button, float opacity) {
    // Kiểm tra xem opacity có nằm trong khoảng từ 0.0 đến 1.0 hay không
    if (opacity < 0.0f) opacity = 0.0f;
    if (opacity > 1.0f) opacity = 1.0f;

    // Chuyển đổi opacity thành một giá trị alpha từ 0 đến 255
    int alpha_value = (int)(opacity * 255.0f);

    // Thiết lập giá trị alpha cho màu sắc
    button->backgroundColor.a = alpha_value;
}


// Vẽ Button
__attribute__((unused)) void DrawButton(const Button button, int radius) {
    DrawRectWithBorderRadius(button.rect, radius, button.backgroundColor);
    // Tính toán kích thước của văn bản
    V2 textSize = MeasureTextEx(button.font, button.value, button.font.baseSize, 1);

    // Tính toán vị trí để văn bản nằm ngay giữa nút
    float textX = button.rect.x + button.rect.width / 2 - textSize.x / 2;
    float textY = button.rect.y + button.rect.height / 2 - textSize.y / 2;

    // Vẽ văn bản
    DrawTextEx(button.font, button.value, (V2) {textX, textY}, button.font.baseSize, 1, button.textColor);
}

// lắng nghe sự kiện onClickButton khi click vào button, đồng thời gọi hàm callback
__attribute__((unused)) void onClickButton(Button button, Callback callback) {
    if (isClicked() && CheckCollisionPointRec(mousePos, button.rect)) {
        callback();
    }
}

// tùy chỉnh con trỏ chuột khi hover vào button
__attribute__((unused)) void onHoverButton(Button button) {
    if (CheckCollisionPointRec(mousePos, button.rect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        return;
    }
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

