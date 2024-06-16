#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stddef.h>
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
#define false 0
#define true 1
typedef void (*Callback)();

//typedef void (*Callbacki)(int);
//
//typedef void (CallbackContainer)(void *);

typedef Vector2 V2;
typedef Texture2D T2;
__attribute__((unused)) typedef enum LEVELS {
    _,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    LEVEL_4,
    LEVEL_5,
    LEVEL_6,
    LEVEL_7,
    LEVEL_8,
    LEVEL_9,
    LEVEL_10,
    LEVEL_11,
    LEVEL_12,
    LEVEL_13,
    LEVEL_14,
    LEVEL_15
} questions;
extern const int SCREEN_WIDTH; /* px */
extern const int SCREEN_HEIGHT; /* px */
extern const int FPS; /* Frames per second */
extern const int PADDING_LEFT; /*px */
extern const int SPACING; /*px */
extern const char *BACKGROUND_IMAGE; /* Đường dẫn tới background */
extern const char *QUESTION_IMAGE; /* Đường dẫn tới background của câu hỏi */
extern const char *LEFT_ANSWER_IMAGE; /* Đường dẫn tới background của đáp án bên trái (A, C) */
extern const char *RIGHT_ANSWER_IMAGE; /* Đường dẫn tới background của đáp án bên phải (B, D) */
extern const char *DEFAULT_FONT;
extern const char *A_ANSWER;
extern const char *A_ANSWER_SELECTED;
extern const char *B_ANSWER;
extern const char *B_ANSWER_SELECTED;
extern const char *C_ANSWER_DIR;
extern const char *C_ANSWER_SELECTED;
extern const char *D_ANSWER_DIR;
extern const char *D_ANSWER_SELECTED;
extern const char *CURRENT_LEVEL_BG;
extern const char *REWARDS_BG;
extern const char *LOGO;
extern const Color TEXT_COLOR;
extern const char *START_BUTTON_DIR;
extern const char *REWARD_BOARD;
extern const char *TITLE_WINDOW_LOGIN;
extern const char *TITLE_WINDOW_GAME;
extern const Color TRANSPARENT;
#endif