#include "assistance.h"

static const int iconWidth = 69;
static const int iconHeight = 42;

void setAssistanceContainer() {
    Image img = LoadImage(ASSISTANCES);
    Rectangle destRect = {0, 12 /** padding **/, img.width / 1.5, img.height / 1.5};
    assistanceContainer = newContainer(img, img, destRect, (V2) {});
    V2 center = getCenter(destRect, (V2) {iconWidth, iconHeight});
    {
        img = LoadImage(FIFTY_FIFTY);
        destRect = (Rectangle) {center.x - PADDING_LEFT - iconWidth, center.y, iconWidth, iconHeight};
        fiftyfiftyAssist.container = newContainer(img, img, destRect, (V2) {});
        fiftyfiftyAssist.isUsed = false;
        img = LoadImage(FIFTY_FIFTY_USED);
        fiftyfiftyAssist.usedContainer = newContainer(img, img, destRect, (V2) {});
    }
    {
        img = LoadImage(PLUS_ONE);
        destRect = (Rectangle){center.x, center.y, iconWidth, iconHeight};
        plusOneAssist.container = newContainer(img, img, destRect, (V2){});
        plusOneAssist.isUsed = false;
        img = LoadImage(PLUS_ONE_USED);
        plusOneAssist.usedContainer = newContainer(img, img, destRect, (V2){});
    }
    {
        img = LoadImage(ASK_EXPERT);
        destRect = (Rectangle){center.x + PADDING_LEFT + iconWidth, center.y, iconWidth, iconHeight};
        askExpertAssist.container = newContainer(img, img, destRect, (V2){});
        askExpertAssist.isUsed = false;
        img = LoadImage(ASK_EXPERT_USED);
        askExpertAssist.usedContainer = newContainer(img, img, destRect, (V2){});
    }
}

void drawAssistanceContainer() {
    DrawContainer(assistanceContainer, 0, WHITE);
    if (!fiftyfiftyAssist.isUsed) {
        DrawContainer(fiftyfiftyAssist.container, 0, WHITE);
    }
    else {
        DrawContainer(fiftyfiftyAssist.usedContainer, 0, WHITE);
    }
    if (!plusOneAssist.isUsed) {
        DrawContainer(plusOneAssist.container, 0, WHITE);
    }
    else {
        DrawContainer(plusOneAssist.usedContainer, 0, WHITE);
    }
    if (!askExpertAssist.isUsed) {
        DrawContainer(askExpertAssist.container, 0, WHITE);
    }
    else {
        DrawContainer(askExpertAssist.usedContainer, 0, WHITE);
    }
}

char *fiftyFifty(char correctAnswer) {
    char *answers = (char *) malloc(4 * sizeof(char));
    for (char c = 'A'; c <= 'D'; ++c) {
        answers[c - 'A'] = c;
    }
    int correctId = correctAnswer - 'A';
    int removeCount = 2;
    char *remainAnswers = (char *) malloc(removeCount * sizeof(char));
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
            remainAnswers[idx++] = answers[i];
        }
    }
    char *set = "ABCD";
    char *res = (char *) malloc(2 * sizeof(char));
    int k = 0;
    for (int i = 0; i < 4; ++i) {
        if (set[i] != remainAnswers[0] && set[i] != remainAnswers[1]) {
            res[k++] = set[i];
        }
    }
    free(answers);
    free(remainAnswers);
    return res;
}

char plusOne(char correctAnswer) {
    float probability = (float) rand() / RAND_MAX;
    if (probability <= 0.75) return correctAnswer;
    char answers[3];
    int idx = 0;
    for (char c = 'A'; c <= 'D'; ++c) {
        if (c != correctAnswer) {
            answers[idx++] = c;
        }
    }
    return answers[rand() % 3];
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