#include "game.h"

Container questionContainer;
Button btn;

static Font fontTemp;
static char *currentContent;
static V2 currMeasureText;

void questionInit() {
    Image questionImg = LoadImage(QUESTION_IMAGE_DIR);
    Rectangle destRect = {0, SCREEN_HEIGHT / 2 - questionImg.height, SCREEN_WIDTH, 128};
    V2 origin = {0, 0};
    ContainerInit(&questionContainer, questionImg, destRect, origin);
    fontTemp = questionContent.font;
    currentContent = questionContent.value;
    currMeasureText = MeasureTextEx(fontTemp, currentContent, 35, 3);
//    ButtonInitWithRect(&btn, questionContainer.destRect, "Đức đẹp trai", LoadFont(DEFAULT_FONT_DIR), TRANSPARENT, YELLOW);
}

void setCurrentQuest() {
    DrawContainer(questionContainer, 0, WHITE);
    DrawUnicodeText(questionContent, (V2) {SCREEN_WIDTH / 2 - currMeasureText.x / 2, SCREEN_HEIGHT / 2 - questionContainer.destRect.height / 2 + currMeasureText.y / 2}, 35, 3, WHITE);
//    DrawButton(btn, 0);
//    printf("current id = %d\n", currentIndexQuestion);
}

int getRandomQuestion(int begin, int end) {
    return rand() % (end - begin + 1) + begin;
}
