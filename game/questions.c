#include "game.h"

struct Question {
    char *content;
    char *answers;
    char *correct_answer;
};

Container currQuestion;

void questionInit() {
    Image questionImg = LoadImage(QUESTION_IMAGE_DIR);
    Rectangle destRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    V2 origin = {0, 0};
    ContainerInit(&currQuestion, questionImg, destRect, origin);
}

void setCurrentQuest() {

}
