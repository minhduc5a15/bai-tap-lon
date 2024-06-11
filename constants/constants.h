#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <raylib.h>
#include <cjson/cJSON.h>
#define mousePos GetMousePosition()

typedef void (*Callback)();

typedef Vector2 V2;
typedef Vector3 V3;
typedef Vector4 V4;
typedef Texture2D T2;
typedef enum QUESTIONS {
    _,
    QUESTION_1,
    QUESTION_2,
    QUESTION_3,
    QUESTION_4,
    QUESTION_5,
    QUESTION_6,
    QUESTION_7,
    QUESTION_8,
    QUESTION_9,
    QUESTION_10,
    QUESTION_11,
    QUESTION_12,
    QUESTION_13,
    QUESTION_14,
    QUESTION_15
} questions;
extern const int SCREEN_WIDTH; /* px */
extern const int SCREEN_HEIGHT; /* px */
extern const int FPS; /* Frames per second */
extern const int INPUT_PADDING_LEFT; /*px */
extern const char *BACKGROUND_IMAGE_DIR; /* Đường dẫn tới background */
extern const char *QUESTION_IMAGE_DIR; /* Đường dẫn tới background của câu hỏi */
extern const char *DEFAULT_FONT_DIR;
extern const char *START_BUTTON_DIR;
extern const char *TITLE_WINDOW_LOGIN;
extern const char *TITLE_WINDOW_GAME;
extern const Color TRANSPARENT;
#endif