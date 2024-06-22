#include "game.h"

#ifndef STARTED_GAME
#define STARTED_GAME
bool started = false;

void setStarted(bool value) {
    started = value;
}

bool getStarted() {
    return started;
}

#endif // STARTED_GAME

#ifndef CURRENT_ANSWER
#define CURRENT_ANSWER
bool passed = false;

void setPassed(bool value) {
    passed = value;
}

bool getPassed() {
    return passed;
}

#endif // CURRENT_ANSWER

#ifndef CURRENT_LEVEL
#define CURRENT_LEVEL
int currLevel = 0;

void setCurrLevel(int value) {
    currLevel = value;
    return;
}

int getCurrLevel() {
    return currLevel;
}

#endif // CURRENT_LEVEL

#ifndef RUNNING
#define RUNNING
bool running = true;

void setRunning(bool value) {
    running = value;
    return;
}

bool getRunning() {
    return running;
}

#endif // RUNNING
// -----------------------------------------

#ifndef CURRENT_CLICKED_CONTAINER
#define CURRENT_CLICKED_CONTAINER
Container *currentClickContainer = nullptr;

void *setCurrentClickContainer(void *container) {
    currentClickContainer = container;
    return nullptr;
}

void *getCurrentClickContainer() {
    return currentClickContainer;
}

#endif // CURRENT_CLICKED_CONTAINER
// -----------------------------------------

#ifndef CURRENT_ANSWER
#define CURRENT_ANSWER
char *currAnswer = "";

void setCurrAnswer(char *answer) {
    currAnswer = strdup(answer);
}

char *getCurrAnswer() {
    return currAnswer;
}
#endif // CURRENT_ANSWER
// -----------------------------------------

// --------------------- END GAME ---------------------
bool endgame = false;

void setEndgame(bool value) { endgame = value; }

bool getEndgame() { return endgame; }
// -----------------------------------------

// --------------------- SLEEPING ---------------------

bool isSleeping = false;

void setIsSleeping(bool value) {
    isSleeping = value;
}

bool getIsSleeping() { return isSleeping; }

// -------------------- IS INIT --------------------------------

bool isInit = false;

void setIsInit(bool value) {
    isInit = value;
}

bool getIsInit() {
    return isInit;
}
