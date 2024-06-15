#include "game.h"

void onEvents() {
    onHoverContainer(&questionContainer, test);
//    onHoverContainer(&currQuest, test);
    onHoverContainer(&ansContainerA.container, test);
    onHoverContainer(&ansContainerB.container, test);
    onHoverContainer(&ansContainerC.container, test);
    onHoverContainer(&ansContainerD.container, test);
    onClickContainer(ansContainerD.container, setCurrentClickContainer(&ansContainerA.container));
    onClickContainer(ansContainerD.container, setCurrentClickContainer(&ansContainerB.container));
    onClickContainer(ansContainerD.container, setCurrentClickContainer(&ansContainerC.container));
    onClickContainer(ansContainerD.container, setCurrentClickContainer(&ansContainerD.container));
    if (currentHoverContainer == NULL) {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
}