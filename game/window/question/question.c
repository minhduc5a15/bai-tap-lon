#include "question.h"

UnicodeText questionContent;
Question currQuest;
Container questionContainer;
int currIndex;
int fontSize = 42;

Question newQuestion(char *content, Answer answers[], const char *correctAnswer) {
    Question newQuest;
    newQuest.content = content;
    for (int i = 0; i < 4; ++i) {
        newQuest.answers[i] = answers[i];
    }
    newQuest.correctAnswer = strdup(correctAnswer);
    return newQuest;
}

static V2 currMeasureText;
static Texture2D fontTexture;

void getCurrentQuest(int level) {
    currQuest = questionDb[level - 1];
    currIndex = level - 1;
    questionContainer = newContainer(LoadImage(QUESTION_IMAGE_DIR), (Rectangle) {0, 0, SCREEN_WIDTH, 80}, (V2) {0, 0});
    questionContainer.destRect = (Rectangle) {0, SCREEN_HEIGHT / 2 - questionContainer.destRect.height / 2, SCREEN_WIDTH, 80};
    questionContent = newUnicodeText(DEFAULT_FONT_DIR, currQuest.content);
    currMeasureText = MeasureTextEx(questionContent.font, questionContent.value, fontSize, SPACING);
    printf("current question: %s\n", questionContent.value);
}

void drawQuestion() {
    DrawContainer(questionContainer, 0.0f, WHITE);
    DrawUnicodeText(questionContent, (V2) {SCREEN_WIDTH / 2 - currMeasureText.x / 2, SCREEN_HEIGHT / 2 - currMeasureText.y}, fontSize, SPACING, TEXT_COLOR);
}

