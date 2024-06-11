#ifndef CONTAINER_H
#define CONTAINER_H

#include "../common.h"

// Cấu trúc của một container
struct Container {
    Image img; // Hình ảnh của thùng chứa
    T2 texture;
    Rectangle srcRect;
    Rectangle destRect;
    V2 origin;
    char *value;
};

typedef struct Container Container;

// Hàm khởi tạo cho container đồng thời Unload img
void ContainerInit(Container *container, Image img, Rectangle destRect, V2 position);

// Hàm vẽ container
void DrawContainer(Container container, float rotation, Color color);

// Lắng nghe sự kiện onClick cho container
void onClickContainer(Container container, Callback callback);

// Chỉnh sửa giá trị cho Container
void setContainerValue(Container *container, char *value);

// Lắng nghe sự kiện onHover cho container
void onHoverContainer(Container container);

#endif