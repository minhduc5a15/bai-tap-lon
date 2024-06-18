#include "game.h"

static char correctAns;

static void setAnsBackground(AnsContainer *ansContainer, char answer) {
    if (correctAns != answer) return;
    char *dir = nullptr;
    switch (correctAns) {
        case 'A':
            dir = strdup(A_RIGHT_ANSWER);
            break;
        case 'B':
            dir = strdup(B_RIGHT_ANSWER);
            break;
        case 'C':
            dir = strdup(C_RIGHT_ANSWER);
            break;
        case 'D':
            dir = strdup(D_RIGHT_ANSWER);
            break;
        default:
            break;
    }
    printf("dir = %s\n", dir);
    Image img = LoadImage(dir);
    ansContainer->container = newContainer(img, img, ansContainer->container.destRect, (V2){});
}

static void chooseAnswer() {
    currentHoverRect = nullptr;
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    setAnsBackground(&ansContainerA, 'A');
    setAnsBackground(&ansContainerB, 'B');
    setAnsBackground(&ansContainerC, 'C');
    setAnsBackground(&ansContainerD, 'D');
    drawAnswers();
//    wait(2);
    setIsSleeping(false);
    setCurrLevel(getCurrLevel() + 1);
//    setPassed(false);
    printf("CURRENT LEVEL: %d\n", getCurrLevel());
}

static void restart() {
    setPassed(false);
    setCurrLevel(LEVEL_1);
    setEndgame(false);
    createDatabase();
}

static void start() {
    currentHoverRect = nullptr;
    setEndgame(false);
    setStarted(true);
    createDatabase();
}

static void lose() {
    setEndgame(true);
    createDatabase();
}

void onEvents() {
    if (currentHoverRect == NULL) {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    onHoverContainer(&ansContainerA.container, nullptr);
    onHoverContainer(&ansContainerB.container, nullptr);
    onHoverContainer(&ansContainerC.container, nullptr);
    onHoverContainer(&ansContainerD.container, nullptr);
    if (!getStarted()) {
        onHoverStartButton();
        onClickStartButton(start);
        return;
    }
    if (getEndgame()) {
        onClickRestartButton(restart);
        return;
    }
    bool isCorrect = false;
    correctAns = currQuest.correctAnswer[0];
    if (currentHoverRect == &ansContainerA.container.destRect) {
        onClickContainer(ansContainerA.container, correctAns == 'A' ? chooseAnswer : lose);
        return;
    }
    if (currentHoverRect == &ansContainerB.container.destRect) {
        onClickContainer(ansContainerB.container, correctAns == 'B' ? chooseAnswer : lose);
        return;
    }
    if (currentHoverRect == &ansContainerC.container.destRect) {
        onClickContainer(ansContainerC.container, correctAns == 'C' ? chooseAnswer : lose);
        return;
    }
    if (currentHoverRect == &ansContainerD.container.destRect) {
        onClickContainer(ansContainerD.container, correctAns == 'D' ? chooseAnswer : lose);
        return;
    }
}