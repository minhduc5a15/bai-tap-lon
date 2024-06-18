#include "container.h"

Rectangle *currentHoverRect = NULL;

__attribute__((unused)) void containerInit(Container *container, Image img, Image imgSelected, Rectangle destRect, V2 position) {
    *container = (Container) {img, imgSelected, LoadTextureFromImage(img), LoadTextureFromImage(imgSelected), (Rectangle) {0, 0, img.width, img.height}, destRect, position, WHITE, false};
}

Container newContainer(Image img, Image imgSelected, Rectangle destRect, V2 position) {
    Container container = (Container) {img, imgSelected, LoadTextureFromImage(img), LoadTextureFromImage(imgSelected), (Rectangle) {0, 0, img.width, img.height}, destRect, position, WHITE, false};
    return container;
}

__attribute__((unused)) void DrawContainer(Container container, float rotation, Color color) {
    if (container.isHovering) {
        DrawTexturePro(container.textureSelected, container.srcRect, container.destRect, container.origin, rotation, color);
        return;
    }
    DrawTexturePro(container.texture, container.srcRect, container.destRect, container.origin, rotation, color);
}

__attribute__((unused)) void onClickContainer(Container container, Callback callback) {
    if (isClicked() && CheckCollisionPointRec(mousePos, container.destRect)) {
        callback();
        return;
    }
}

__attribute__((unused)) void onHoverContainer(Container *container, Callback callback) {
    if (CheckCollisionPointRec(mousePos, container->destRect)) {
        container->isHovering = true;
        currentHoverRect = &container->destRect;
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        container->isHovering = false;
        if (currentHoverRect == &container->destRect) {
            currentHoverRect = NULL;
        }
    }
}
