#include "functions.h"

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

bool isClicked() {
    return IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void DrawRectWithBorderRadius(const Rectangle rect, int radius, Color color) {
    // Vẽ hai hình chữ nhật
    DrawRectangle(rect.x + radius, rect.y, rect.width - 2 * radius, rect.height, color);
    DrawRectangle(rect.x, rect.y + radius, rect.width, rect.height - 2 * radius, color);

    // Vẽ bốn góc cong
    DrawCircleSector((Vector2) {rect.x + radius, rect.y + radius}, radius, 180, 270, 36, color);
    DrawCircleSector((Vector2) {rect.x + rect.width - radius, rect.y + radius}, radius, 270, 360, 36, color);
    DrawCircleSector((Vector2) {rect.x + radius, rect.y + rect.height - radius}, radius, 90, 180, 36, color);
    DrawCircleSector((Vector2) {rect.x + rect.width - radius, rect.y + rect.height - radius}, radius, 0, 90, 36, color);
}
