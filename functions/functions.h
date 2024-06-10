#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../constants/constants.h"
#include "../components/headers.h"
int max(int a, int b);

int min(int a, int b);

void DrawRectWithBorderRadius(const Rectangle rect, int radius, Color color);

bool isClicked();

#endif

