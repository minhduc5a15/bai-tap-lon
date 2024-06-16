#include "question.h"

UnicodeText questionContent;
Question currQuest;
Container questionContainer;
static int fontSize = 32;
static V2 currMeasureText;

void getCurrentQuest(int level) {
    setCurrLevel(level);
    currQuest = questionDb[level];
    auto img = LoadImage(QUESTION_IMAGE);
    questionContainer = newContainer(img, img, (Rectangle) {0, 0, 1075, 90}, (V2) {0, 0});
    questionContainer.destRect = (Rectangle) {0, SCREEN_HEIGHT / 2 + 135, SCREEN_WIDTH, 90};
    questionContent = newUnicodeText(DEFAULT_FONT, currQuest.content);
    currMeasureText = MeasureTextEx(questionContent.font, questionContent.text, fontSize, SPACING);
    printf("current question: %s\n", questionContent.text);
}

void drawQuestion() {
    DrawContainer(questionContainer, 0.0f, questionContainer.hoverColor);
    DrawUnicodeText(questionContent, getCenter(questionContainer.destRect, currMeasureText), fontSize, SPACING, TEXT_COLOR);
}

