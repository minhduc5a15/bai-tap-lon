#include "assistance.h"

int *audiencePoll(char correctAnswer) {
    int *percentages = (int *) calloc(4, sizeof(int));
    int correctId = correctAnswer - 'A';
    percentages[correctId] = 70 + rand() % 21;
    int remain = 100 - percentages[correctId];
    int other[3];
    int idx = 0;
    for (int i = 0; i < 4; ++i) {
        if (i != correctId) {
            other[idx++] = i;
        }
    }
    percentages[other[0]] = rand() % (remain + 1);
    remain -= percentages[other[0]];
    percentages[other[1]] = rand() % (remain + 1);
    remain -= percentages[other[1]];
    percentages[other[2]] = remain;
    return percentages;
}

char *fiftyFifty(char correctAnswer) {
    char *answers = (char *) malloc(4 * sizeof(char));
    for (char c = 'A'; c <= 'D'; ++c) {
        answers[c - 'A'] = c;
    }
    int correctId = correctAnswer - 'A';
    int removeCount = 2;
    char *res = (char *) malloc(removeCount * sizeof(char));
    int indices[3];
    int idx = 0;
    for (int i = 0; i < 4; ++i) {
        if (i != correctId) {
            indices[idx++] = i;
        }
    }
    while (removeCount > 0) {
        int randIndex = rand() % 3;
        if (answers[indices[randIndex]] != '\0') {
            answers[indices[randIndex]] = '\0';
            removeCount--;
        }
    }
    idx = 0;
    for (int i = 0; i < 4; ++i) {
        if (answers[i] != '\0') {
            res[idx++] = answers[i];
        }
    }
    free(answers);
    return res;
}

char askExpert(char correctAnswer) {
    float probability = (float) rand() / RAND_MAX;
    if (probability <= 0.9) return correctAnswer;
    char answers[3];
    int idx = 0;
    for (char c = 'A'; c <= 'D'; ++c) {
        if (c != correctAnswer) {
            answers[idx++] = c;
        }
    }
    return answers[rand() % 3];
}