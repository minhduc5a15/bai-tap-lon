#ifndef CONTAINER_H
#define CONTAINER_H

#include "../common.h"

struct Text {
    char *value;
    Font font;
    Color color;
};
typedef struct Text Text;

struct Container {
    Image img; // Hình ảnh của thùng chứa
    Image imgSelected;
    T2 texture;
    T2 textureSelected;
    Rectangle srcRect;
    Rectangle destRect;
    V2 origin;
    Color hoverColor;
    bool isHovering;
};

typedef struct Container Container;

// Hàm khởi tạo cho container đồng thời Unload img
void containerInit(Container *container, Image img, Image imgSelected, Rectangle destRect, V2 position);

// Hàm tạo một container mới
Container newContainer(Image img, Image imgSelected, Rectangle destRect, V2 position);

// Hàm vẽ container
void DrawContainer(Container container, float rotation, Color color);

// Lắng nghe sự kiện onClick cho container
void onClickContainer(Container container, Callback callback);

// Lắng nghe sự kiện onHover cho container
void onHoverContainer(Container *container, Callback callback);

#endif