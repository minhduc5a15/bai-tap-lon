#include "game.h"

static void *cb(AnsContainer ansContainer, char *ans) {
    if (currentHoverContainer) printf("%s\n", ans);
}

void onEvents() {
    onHoverContainer(&questionContainer, nullptr);
    onHoverContainer(&ansContainerA.container, nullptr);
    onHoverContainer(&ansContainerB.container, nullptr);
    onHoverContainer(&ansContainerC.container, nullptr);
    onHoverContainer(&ansContainerD.container, nullptr);
    onClickContainer(ansContainerA.container, setCurrLevel, getCurrLevel() + 1);
    onClickContainer(ansContainerB.container, setCurrLevel, getCurrLevel() + 1);
    onClickContainer(ansContainerC.container, setCurrLevel, getCurrLevel() + 1);
    onClickContainer(ansContainerD.container, setCurrLevel, getCurrLevel() + 1);
    if (currentHoverContainer == NULL) {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
}