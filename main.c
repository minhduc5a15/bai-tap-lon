#include "game/game.h"

Question *questionDb = NULL;
Question currentQuestion;
int length, currentIndexQuestion;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_LOGIN);
    SetTargetFPS(FPS);
    // Khởi tạo background
    saveData(&questionDb, &length);
    currentIndexQuestion = getRandomQuestion(1, length) - 1;
    backgroundImageInit();
    // Tải dữ liệu
    for (int i = 0; i < length; i++) {
        printf("question: %s\n", questionDb[i].content);
    }
    printf("length: %d, current id: %d\n", length, currentIndexQuestion);
    currentQuestion = questionDb[currentIndexQuestion];
    questionInit();
    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            setBackgroundImage();
            setCurrentQuest();
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
