#include "game.h"

int currLevel = 0;
bool running = false;
Container *currentClickContainer = NULL;

void setCurrLevel(int value) {
    currLevel = value;
}

void setRunning() {
    running = !running;
}

bool getRunning() {
    return running;
}

int getCurrLevel() {
    return currLevel;
}

void *setCurrentClickContainer(void *container) {
    currentClickContainer = container;
    return nullptr;
}

void *getCurrentClickContainer() {
    return currentClickContainer;
}