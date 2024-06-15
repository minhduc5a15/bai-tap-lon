#include "common.h"

int window() {
    setBackgroundImage();
    drawQuestion();
    drawAnswers();
    onEvents();
    return 0;
}