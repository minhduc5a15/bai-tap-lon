#include "container.h"

__attribute__((unused)) void ContainerInit(Container *container, Image img, Rectangle destRect, V2 position) {
    *container = (Container) {img, LoadTextureFromImage(img), (Rectangle) {0, 0, img.width, img.height}, destRect, position, ""};
//    UnloadTexture(container->texture);
    UnloadImage(container->img); // xử lý unload img
}

__attribute__((unused)) void DrawContainer(Container container, float rotation, Color color) {
    DrawTexturePro(container.texture, container.srcRect, container.destRect, container.origin, rotation, color);
}

__attribute__((unused)) void onClickContainer(Container container, Callback callback) {
    if (isClicked() && CheckCollisionPointRec(mousePos, container.destRect)) {
        callback();
    }
}

__attribute__((unused)) void setContainerValue(Container *container, char *value) {
    container->value = value;
}
__attribute__((unused)) void onHoverContainer(Container container) {
    if (CheckCollisionPointRec(mousePos, container.destRect)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
}
