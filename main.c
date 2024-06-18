#include "common.h"

int main() {
    srand(time(NULL));
    SetTraceLogLevel(LOG_NONE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_GAME);
    SetTargetFPS(FPS);
    backgroundImageInit();
    createDatabase();
    startGame();
    endGame();
    setCurrLevel(LEVEL_1);
    while (!WindowShouldClose()) {
        if (!getPassed() && getCurrLevel() <= LEVEL_15) {
            int level = getCurrLevel();
            setPassed(true);
            setAnswers(level);
            getCurrentQuest(level);
            setLevelContainer(level);
            setRewardContainer(level);
        }
        BeginDrawing();
        {
            if (!getStarted()) {
                drawStartWindow();
            }
            else {
                if (getEndgame()) {
                    drawEndgameWindow();
                }
            }
            if (getStarted() && !getEndgame()) {
                drawBackgroundImage();
                drawQuestion();
                drawAnswers();
                drawRewardContainer();
            }
            onEvents();
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
