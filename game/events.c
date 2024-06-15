#include "game.h"

static void callback() {
    setCurrLevel(getCurrLevel() + 1);
    setPassed(false);
    printf("CURRENT LEVEL: %d\n", getCurrLevel());
}

void onEvents() {
    onHoverContainer(&questionContainer, nullptr);
    onHoverContainer(&ansContainerA.container, nullptr);
    onHoverContainer(&ansContainerB.container, nullptr);
    onHoverContainer(&ansContainerC.container, nullptr);
    onHoverContainer(&ansContainerD.container, nullptr);
    if (currentHoverContainer == NULL) {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        return;
    }
    if (currentHoverContainer == &ansContainerA.container) {
        onClickContainer(ansContainerA.container, callback);
        return;
    }
    if (currentHoverContainer == &ansContainerB.container) {
        onClickContainer(ansContainerB.container, callback);
        return;
    }
    if (currentHoverContainer == &ansContainerC.container) {
        onClickContainer(ansContainerC.container, callback);
        return;
    }
    if (currentHoverContainer == &ansContainerD.container) {
        onClickContainer(ansContainerD.container, callback);
        return;
    }
}