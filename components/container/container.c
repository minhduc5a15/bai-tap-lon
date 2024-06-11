#include "container.h"

__attribute__((unused)) void ContainerInit(Container *container, Image img, Rectangle destRect, V2 position) {
    *container = (Container) {img, LoadTextureFromImage(img), (Rectangle) {0, 0, img.width, img.height}, destRect, position, nullptr};
//    UnloadTexture(container->texture);
    UnloadImage(container->img); // xử lý unload img
}

__attribute__((unused)) void DrawContainer(Container container, float rotation, Color color) {
    DrawTexturePro(container.texture, container.srcRect, container.destRect, container.origin, rotation, color);

    V2 textSize = MeasureTextEx(container.value.font, container.value.value, 100, 1);
    // Tính toán vị trí để văn bản nằm ngay giữa nút
    float textX = container.destRect.x + container.destRect.width / 2 - textSize.x / 2;
    float textY = container.destRect.y + container.destRect.height / 2 - textSize.y / 2;

    DrawTextEx(container.value.font, container.value.value, (V2){textX, textY}, 100, 1, container.value.color);
}

__attribute__((unused)) void onClickContainer(Container container, Callback callback) {
    if (isClicked() && CheckCollisionPointRec(mousePos, container.destRect)) {
        callback();
    }
}

__attribute__((unused)) void setContainerValue(Container *container, Text value) {
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
