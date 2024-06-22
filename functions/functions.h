#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../constants/constants.h"
#include "../components/components.h"

void DrawRectWithBorderRadius(const Rectangle rect, int radius, Color color);

bool isClicked();

V2 getCenter(Rectangle parent, V2 child);

V2 getRight(Rectangle parent, V2 child, int padding_left, int bonus_left);

Color setOpacity(Color color, float opacity);

char *addStr(const char *s1, const char *s2);

void onClickRect(Rectangle rect, Callback callback);

void onHoverRect(Rectangle rect);

#endif

