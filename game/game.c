#include "game.h"

// --------------------- LEVEL ---------------------
int currLevel = 0;

void setCurrLevel(int value) {
    currLevel = value;
    return;
}

int getCurrLevel() {
    return currLevel;
}

// -----------------------------------------

// --------------------- RUNNING ---------------------
bool running = false;

void setRunning(bool value) {
    running = value;
    return;
}

bool getRunning() {
    return running;
}

// -----------------------------------------

// --------------------- CURRENT CLICKED CONTAINER ---------------------
Container *currentClickContainer = NULL;


void *setCurrentClickContainer(void *container) {
    currentClickContainer = container;
    return nullptr;
}

void *getCurrentClickContainer() {
    return currentClickContainer;
}

// -----------------------------------------

// --------------------- CURRENT ANSWER ---------------------

char *currAnswer = "";

void setCurrAnswer(char *answer) {
    currAnswer = strdup(answer);
}

char *getCurrAnswer() {
    return currAnswer;
}

// -----------------------------------------

