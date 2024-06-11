#include "game.h"

Container questionContainer;
//Question currentQuestion, *questionDb;
//int currentIndexQuestion;
Button btn;

void questionInit() {
    Image questionImg = LoadImage(QUESTION_IMAGE_DIR);
    Rectangle destRect = {0, SCREEN_HEIGHT / 2 - questionImg.height, SCREEN_WIDTH, 128};
    V2 origin = {0, 0};
    ContainerInit(&questionContainer, questionImg, destRect, origin);
    ButtonInitWithRect(&btn, questionContainer.destRect, "Đức đẹp trai", LoadFont(DEFAULT_FONT_DIR), TRANSPARENT, YELLOW);
    printf("%s\n", btn.value);
}

void setCurrentQuest() {
    DrawContainer(questionContainer, 0, WHITE);
    DrawButton(btn, 0);
//    printf("current id = %d\n", currentIndexQuestion);
}

int getRandomQuestion(int begin, int end) {
    return rand() % (end - begin + 1) + begin;
}
