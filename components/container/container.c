#include "container.h"

bool isHovering = false;
Container *currentHoverContainer = NULL;

//extern void setCurrLevel(int value);
//extern int getCurrLevel();

__attribute__((unused)) void containerInit(Container *container, Image img, Image imgSelected, Rectangle destRect, V2 position) {
    *container = (Container) {img, imgSelected, LoadTextureFromImage(img), LoadTextureFromImage(imgSelected), (Rectangle) {0, 0, img.width, img.height}, destRect, position, WHITE, false};
}

Container newContainer(Image img, Image imgSelected, Rectangle destRect, V2 position) {
    Container container = (Container) {img, imgSelected, LoadTextureFromImage(img), LoadTextureFromImage(imgSelected), (Rectangle) {0, 0, img.width, img.height}, destRect, position, WHITE, false};
    return container;
}

__attribute__((unused)) void DrawContainer(Container container, float rotation, Color color) {
    if (container.isHovering) {
//        color = container.hoverColor; // Sử dụng màu sắc khi di chuột qua nếu đang di chuột qua
        DrawTexturePro(container.textureSelected, container.srcRect, container.destRect, container.origin, rotation, color);
        return;
    }
    DrawTexturePro(container.texture, container.srcRect, container.destRect, container.origin, rotation, color);
}

__attribute__((unused)) void onClickContainer(Container container, Callback callback) {
    if (isClicked() && CheckCollisionPointRec(mousePos, container.destRect)) {
//        printf("button a\n");
        callback();
        return;
    }
}

//static bool check = false;
__attribute__((unused)) void onHoverContainer(Container *container, Callback callback) {
    if (CheckCollisionPointRec(mousePos, container->destRect)) {
//        callback();
        container->isHovering = true;
        container->hoverColor = WHITE;
        currentHoverContainer = container;
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        container->isHovering = false;
        container->hoverColor = WHITE;
        if (currentHoverContainer == container) {
            currentHoverContainer = NULL;
        }
    }
}
