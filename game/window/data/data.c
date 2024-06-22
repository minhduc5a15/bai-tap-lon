#include "data.h"

__attribute__((unused)) static void printQuest(Question question) {
    printf("Content: %s\n", question.content);
    printf("Answer A: %s\n", question.answers[0].value.text);
    printf("Answer B: %s\n", question.answers[1].value.text);
    printf("Answer C: %s\n", question.answers[2].value.text);
    printf("Answer D: %s\n", question.answers[3].value.text);
    printf("Correct answer: %s\n", question.correctAnswer);
}

void createDatabase() {
    Question *temp1_5;
    saveData(&temp1_5, &lengthQuestions1_5, "1-5");
    Question *temp6_10;
    saveData(&temp6_10, &lengthQuestions6_10, "6-10");
    Question *temp11_15;
    saveData(&temp11_15, &lengthQuestions11_15, "11-15");
    questions1_5 = generateQuestions(1, lengthQuestions1_5);
    questions6_10 = generateQuestions(1, lengthQuestions6_10);
    questions11_15 = generateQuestions(1, lengthQuestions11_15);
    questionDb = (Question *) malloc(16 * sizeof(Question));
    for (int i = 0; i < 5; ++i) {
        questionDb[i + 1] = temp1_5[questions1_5[i] - 1];
        questionDb[i + 6] = temp6_10[questions6_10[i] - 1];
        questionDb[i + 11] = temp6_10[questions11_15[i] - 1];
    }
}