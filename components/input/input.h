#ifndef INPUT_H
#define INPUT_H

#include "../common.h"

// Định nghĩa cấu trúc Input để lưu trữ thông tin về một thanh input
struct Input {
    char *placeHolder; // Văn bản hiển thị khi thanh input trống
    char *value; // Giá trị hiện tại của thanh input
    int x; // Tọa độ x của thanh input trên màn hình
    int y; // Tọa độ y của thanh input trên màn hình
    int maxLength; // Độ dài tối đa cho phép của giá trị nhập vào
    int fontSize; // Kích thước của văn bản
    int width; // Chiều rộng của thanh input
    int height; // Chiều cao của thanh input
    bool isMouseEnter; // Biến kiểm tra xem con trỏ chuột có đang ở trên thanh input hay không
    int currentLength; // Độ dài hiện tại của giá trị nhập vào
    Font font; // Kiểu font chữ của thanh input
    Rectangle textBox; // Hình chữ nhật biểu diễn thanh input trên màn hình
};

typedef struct Input Input; // Định nghĩa lại tên cho struct Input

// Khởi tạo thanh input với các thông số cụ thể
void inputInit(Input *input, const Font font, const char *place_holder, int width, int height, int x, int y, int fontSize);

// Hàm xử lý sự kiện thay đổi giá trị của thanh input
void onChange(Input *input);

// Hàm vẽ thanh input lên mànd gh hình
void DrawInput(Input input);

#endif
