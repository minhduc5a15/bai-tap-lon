#include "dialog.h"

static UnicodeText BtnContent;

void setDialog(Dialog *dialog, Rectangle rectangle, Rectangle button, char *content) {
    dialog->isOpening = false;
    dialog->container = rectangle;
    dialog->content = newUnicodeText(DEFAULT_FONT, content);
    dialog->button = (Rectangle) {dialog->container.x + (dialog->container.width - button.width) / 2, dialog->container.y + dialog->container.height - button.height / 2, button.width, button.height};
    BtnContent = newUnicodeText(DEFAULT_FONT, "Tiếp tục");
}
void DrawDialog() {
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, setOpacity(BLACK, 0.35));
    DrawRectangleRec(currentDialog.container, (Color) {32, 60, 124, 255});
    DrawRectangleRec(currentDialog.button, (Color) {38, 77, 124, 255});
    DrawUnicodeText(currentDialog.content, getCenter(currentDialog.container, MeasureTextEx(currentDialog.content.font, currentDialog.content.text, 32, 0)), 32, 0, YELLOW);
    DrawUnicodeText(BtnContent, getCenter(currentDialog.button, MeasureTextEx(BtnContent.font, BtnContent.text, 25, 0)), 25, 0, YELLOW);
}