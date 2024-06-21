#include "game.h"

// --------------------- IS STARTED GAME ---------------------
bool started = false;

void setStarted(bool value) {
    started = value;
    printf("started: %d\n", started);
}

bool getStarted() {
    return started;
}
// ------------------------------------------

// --------------------- CURRENT ANSWER ---------------------
bool passed = false;

void setPassed(bool value) {
    passed = value;
}

bool getPassed() {
    return passed;
}
// ------------------------------------------


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
bool running = true;

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
