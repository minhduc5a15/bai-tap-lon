#include "common.h"

int main() {
    srand(time(NULL));
    SetTraceLogLevel(LOG_NONE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE_WINDOW_GAME);
    InitAudioDevice();
    SetTargetFPS(FPS);
    backgroundImageInit();
    createDatabase();
    startGame();
    endGame();
    setCurrLevel(LEVEL_1);
    setAssistanceContainer();
    while (!WindowShouldClose()) {
        if (!getPassed() && getCurrLevel() <= LEVEL_15) {
            int level = getCurrLevel();
            if (!getIsInit()) {
                setAnswers(level);
                getCurrentQuest(level);
                setLevelContainer(level);
                setRewardContainer(level);
                setIsInit(true);
            }
        }
        else if (getPassed()) {
            sleep(1);
            setPassed(false);
        }
        BeginDrawing();
        {
            onEvents();
            if (!getStarted()) {
                drawStartWindow();
            }
            if (getStarted()) {
                drawBackgroundImage();
                drawQuestion();
                drawAnswers();
                drawRewardContainer();
                drawAssistanceContainer();
                if (currentDialog.isOpening) {
                    DrawDialog();
                }
            }
            if (getEndgame()) {
                printf("end game\n");
                drawEndgameWindow();
            }
        }
        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
