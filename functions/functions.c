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

void DrawRectWithBorderRadius(Rectangle rect, int radius, Color color) {
    // Vẽ hai hình chữ nhật
    DrawRectangle(rect.x, rect.y + radius, rect.width, rect.height - 2 * radius, color);
    DrawRectangle(rect.x + radius, rect.y, rect.width - 2 * radius, rect.height, color);

    // Vẽ bốn góc cong
    DrawCircleSector((V2) {rect.x + radius, rect.y + radius}, radius, 180, 270, 36, color);
    DrawCircleSector((V2) {rect.x + rect.width - radius, rect.y + radius}, radius, 270, 360, 36, color);
    DrawCircleSector((V2) {rect.x + radius, rect.y + rect.height - radius}, radius, 90, 180, 36, color);
    DrawCircleSector((V2) {rect.x + rect.width - radius, rect.y + rect.height - radius}, radius, 0, 90, 36, color);
}

V2 getCenter(Rectangle parent, V2 child) {
    return (V2) {parent.x + (parent.width - child.x) / 2, parent.y + parent.height / 2 - child.y / 2};
}

V2 getRight(Rectangle parent, V2 child, int padding_left, int bonus_left) {
    return (V2) {parent.x + bonus_left + padding_left, parent.y + parent.height / 2 - child.y / 2};
}

void test() {
    printf("Hello world\n");
}

char *addStr(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}