#include "common.h"

int window() {
    drawBackgroundImage();
    drawQuestion();
    drawAnswers();
    onEvents();
    return 0;
}