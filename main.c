#include "game/game.h"

Question *questionDb = nullptr;
Question currentQuestion;
UnicodeText questionContent;
int length, currentIndexQuestion;
int *questions1_5;
int *questions2_5;
int *questions3_5;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_GAME);
    SetTargetFPS(FPS);
    // Khởi tạo background
    saveData(&questionDb, &length, "6-10");
    currentIndexQuestion = getRandomQuestion(1, length) - 1;
    backgroundImageInit();
    // Tải dữ liệu
    currentQuestion = questionDb[currentIndexQuestion];
    UnicodeTextInit(&questionContent, DEFAULT_FONT_DIR, currentQuestion.content);
    questionInit();
    questions1_5 = generateQuestions(0, length);
    for (int i = 0; i < 5; ++i) {
        printf("%d ", questions1_5[i]);
    }
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
