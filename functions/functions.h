#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../constants/constants.h"
#include "../components/components.h"

int max(int a, int b);

int min(int a, int b);

void DrawRectWithBorderRadius(const Rectangle rect, int radius, Color color);

bool isClicked();

V2 getCenter(Rectangle parent, V2 child);

V2 getRight(Rectangle parent, V2 child, int padding_left, int bonus_left);

void test();

void setTimeout(Callback callback, int seconds);

char *addStr(const char *s1, const char *s2);

#endif

