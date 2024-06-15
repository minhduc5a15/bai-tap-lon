#include "answers.h"

V2 rightA, rightB, rightC, rightD;

static int fontSize = 32;

void setAnswers(int level) {
    Image imgA = LoadImage(A_ANSWER_DIR), imgA_selected = LoadImage(A_ANSWER_SELECTED_DIR);
    Image imgB = LoadImage(B_ANSWER_DIR), imgB_selected = LoadImage(B_ANSWER_SELECTED_DIR);
    Image imgC = LoadImage(C_ANSWER_DIR), imgC_selected = LoadImage(C_ANSWER_SELECTED_DIR);
    Image imgD = LoadImage(D_ANSWER_DIR), imgD_selected = LoadImage(D_ANSWER_SELECTED_DIR);
    auto curr = questionDb[getCurrLevel()];
    ansContainerA.answer = curr.answers[0],
    ansContainerA.container = newContainer(imgA, imgA_selected, (Rectangle) {0, 588, 640, 57}, (V2) {}),
    ansContainerB.answer = curr.answers[1],
    ansContainerB.container = newContainer(imgB, imgB_selected, (Rectangle) {SCREEN_WIDTH - imgB.width, 588, 640, 57}, (V2) {}),
    ansContainerC.answer = curr.answers[2],
    ansContainerC.container = newContainer(imgC, imgC_selected, (Rectangle) {0, 645, 640, 57}, (V2) {}),
    ansContainerD.answer = curr.answers[3],
    ansContainerD.container = newContainer(imgD, imgD_selected, (Rectangle) {SCREEN_WIDTH - imgD.width, 645, 640, 57}, (V2) {}),
    ansContainerA.answer.isCorrect = !strcmp("A", curr.correctAnswer),
    ansContainerB.answer.isCorrect = !strcmp("B", curr.correctAnswer),
    ansContainerC.answer.isCorrect = !strcmp("C", curr.correctAnswer),
    ansContainerD.answer.isCorrect = !strcmp("D", curr.correctAnswer);
    ansContainerA.answer.value = newUnicodeText(DEFAULT_FONT_DIR, addStr("A: ", ansContainerA.answer.value.text));
    ansContainerB.answer.value = newUnicodeText(DEFAULT_FONT_DIR, addStr("B: ", ansContainerB.answer.value.text));
    ansContainerC.answer.value = newUnicodeText(DEFAULT_FONT_DIR, addStr("C: ", ansContainerC.answer.value.text));
    ansContainerD.answer.value = newUnicodeText(DEFAULT_FONT_DIR, addStr("D: ", ansContainerD.answer.value.text));
    printf("Answer A: %s\n", ansContainerA.answer.value.text);
    printf("Answer B: %s\n", ansContainerB.answer.value.text);
    printf("Answer C: %s\n", ansContainerC.answer.value.text);
    printf("Answer D: %s\n", ansContainerD.answer.value.text);
    rightA = getRight(ansContainerA.container.destRect, MeasureTextEx(ansContainerA.answer.value.font, ansContainerA.answer.value.text, fontSize, SPACING), PADDING_LEFT, 246);
    rightB = getRight(ansContainerB.container.destRect, MeasureTextEx(ansContainerB.answer.value.font, ansContainerB.answer.value.text, fontSize, SPACING), PADDING_LEFT, 0);
    rightC = getRight(ansContainerC.container.destRect, MeasureTextEx(ansContainerC.answer.value.font, ansContainerC.answer.value.text, fontSize, SPACING), PADDING_LEFT, 246);
    rightD = getRight(ansContainerD.container.destRect, MeasureTextEx(ansContainerD.answer.value.font, ansContainerD.answer.value.text, fontSize, SPACING), PADDING_LEFT, 0);
}

void drawAnswers() {
    DrawContainer(ansContainerA.container, 0, WHITE);
    DrawContainer(ansContainerB.container, 0, WHITE);
    DrawContainer(ansContainerD.container, 0, WHITE);
    DrawContainer(ansContainerC.container, 0, WHITE);
    DrawUnicodeText(ansContainerA.answer.value, rightA, fontSize, SPACING, WHITE);
    DrawUnicodeText(ansContainerB.answer.value, rightB, fontSize, SPACING, WHITE);
    DrawUnicodeText(ansContainerC.answer.value, rightC, fontSize, SPACING, WHITE);
    DrawUnicodeText(ansContainerD.answer.value, rightD, fontSize, SPACING, WHITE);
}