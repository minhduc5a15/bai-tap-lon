#include "game.h"

static void callback() {
    setCurrLevel(getCurrLevel() + 1);
    setPassed(false);
    printf("CURRENT LEVEL: %d\n", getCurrLevel());
}

static void lose() {
    setRunning(false);
}

void onEvents() {
    onHoverContainer(&questionContainer, nullptr);
    onHoverContainer(&ansContainerA.container, nullptr);
    onHoverContainer(&ansContainerB.container, nullptr);
    onHoverContainer(&ansContainerC.container, nullptr);
    onHoverContainer(&ansContainerD.container, nullptr);
    char correctAns = currQuest.correctAnswer[0];
    if (currentHoverContainer == NULL) {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        return;
    }
    if (currentHoverContainer == &ansContainerA.container) {
        onClickContainer(ansContainerA.container, correctAns == 'A' ? callback : lose);
        return;
    }
    if (currentHoverContainer == &ansContainerB.container) {
        onClickContainer(ansContainerB.container, correctAns == 'B' ? callback : lose);
        return;
    }
    if (currentHoverContainer == &ansContainerC.container) {
        onClickContainer(ansContainerC.container, correctAns == 'C' ? callback : lose);
        return;
    }
    if (currentHoverContainer == &ansContainerD.container) {
        onClickContainer(ansContainerD.container, correctAns == 'D' ? callback : lose);
        return;
    }
}