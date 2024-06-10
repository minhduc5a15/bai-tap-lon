#ifndef BUTTON_H
#define BUTTON_H

#include "../common.h"

struct Button {
    Rectangle rect;
    char *value;
    Font font;
    Color backgroundColor;
    Color textColor;
};

typedef struct Button Button;

__attribute__((unused)) void ButtonInit(Button *button, float x, float y, float width, float height, const char *value, Font buttonFont, Color backgroundColor, Color textColor);

__attribute__((unused)) void ButtonInitWithRect(Button *button, Rectangle rect, const char *value, Font buttonFont, Color backgroundColor, Color textColor);

__attribute__((unused)) void setOpacity(Button *button, float opacity);

void Hello();

void onClick(Button button, Callback callback);

void DrawButton(const Button button, int radius);

void onHover(Button button);

#endif