#ifndef WINDOW_START_H
#define WINDOW_START_H

#include "../common.h"

Container startWindow;
Container startButton;

void startGame();
void drawStartWindow();
void onClickStartButton(Callback callback);
void onHoverStartButton();
#endif // WINDOW_START_H