#include "question.h"

UnicodeText questionContent;
Question currQuest;
Container questionContainer;
static int fontSize;
static V2 currMeasureText;

void getCurrentQuest(int level) {
    setCurrLevel(level);
    currQuest = questionDb[level];
    fontSize = 32;
    Image img = LoadImage(QUESTION_IMAGE);
    questionContainer = newContainer(img, img, (Rectangle) {0, 0, 1075, 90}, (V2) {0, 0});
    questionContainer.destRect = (Rectangle) {0, SCREEN_HEIGHT / 2 + 135, SCREEN_WIDTH, 90};
    questionContent = newUnicodeText(DEFAULT_FONT, currQuest.content);
    currMeasureText = MeasureTextEx(questionContent.font, questionContent.text, fontSize, SPACING);
    while (currMeasureText.x > 690) currMeasureText = MeasureTextEx(questionContent.font, questionContent.text, --fontSize, SPACING);
}

void drawQuestion() {
    DrawContainer(questionContainer, 0.0f, questionContainer.hoverColor);
    DrawUnicodeText(questionContent, getCenter(questionContainer.destRect, currMeasureText), fontSize, SPACING, TEXT_COLOR);
}

