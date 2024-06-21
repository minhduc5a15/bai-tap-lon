#ifndef GAME_H
#define GAME_H

#include "../common.h"
// -------------------Global Variables --------------------------------

extern int currLevel;
extern bool running;
extern bool passed;
extern bool started;
extern char *currAnswer;
extern bool endgame;
extern bool isSleeping;
extern bool isInit;
extern Container *currentClickContainer;

void setIsInit(bool value);

bool getIsInit();

void setIsSleeping(bool value);

bool getIsSleeping();

void setEndgame(bool value);

bool getEndgame();

void setRunning(bool value);

bool getRunning();

void *setCurrentClickContainer(void *container);

void *getCurrentClickContainer();

void setCurrLevel(int value);

int getCurrLevel();

void setCurrAnswer(char *answer);

char *getCurrAnswer();

void setPassed(bool value);

bool getPassed();

void setStarted(bool value);

bool getStarted();

// ----------------------------------------------------------------
#ifndef STRUCT_H
struct Answer {
    char *answer; // A, B, C or D
    UnicodeText value;
    bool isCorrect;
};

struct Question {
    char *content;
    struct Answer answers[4];
    char *correctAnswer;
};

struct AnsContainer {
    struct Answer answer;
    Container container;
};

struct Assistance {
    Container container;
    Container usedContainer;
    bool isUsed;
};

struct Dialog {
    Rectangle container;
    Rectangle button;
    UnicodeText content;
    float radius;
    bool isOpening;
};

typedef struct Answer Answer;
typedef struct Question Question;
typedef struct Assistance Assistance;
typedef struct AnsContainer AnsContainer;
typedef struct Dialog Dialog;
#endif

// ------------------------background------------------------
extern Container bgContainer;
// ------------------------------------------------

#ifndef WINDOW_START_H
extern Container startWindow;
extern Container startButton;

extern void startGame();

extern void drawStartWindow();

extern void onClickStartButton(Callback callback);

#endif

#ifndef WINDOW_QUESTION_H
extern UnicodeText questionContent;
extern Container questionContainer;
extern Question currQuest;

extern void getCurrentQuest(int level);

extern void drawQuestion(void);

#endif // WINDOW_QUESTION_H

#ifndef WINDOW_DATA_H

extern Question *questionDb;
extern int *questions1_5;
extern int *questions6_10;
extern int *questions11_15;
extern int lengthQuestions1_5;
extern int lengthQuestions6_10;
extern int lengthQuestions11_15;

extern void createDatabase();

#endif // WINDOW_DATA_H

#ifndef WINDOW_ANSWERS_H
extern AnsContainer ansContainerA;
extern AnsContainer ansContainerB;
extern AnsContainer ansContainerC;
extern AnsContainer ansContainerD;

extern void setAnswers(int level);

extern void showCorrectAnswer();

extern void drawAnswers();

#endif // WINDOW_ANSWERS_H
struct Window {
    int level;
    Question question;
};
typedef struct Window Window;

void NewLevel();

Question newQuestion(char *content, Answer answers[], const char *correctAnswer);

// ----------------------Background----------------------
extern void backgroundImageInit(void);

extern void drawBackgroundImage(void);

// ----------------------Level----------------------

#ifndef WINDOW_LEVEL_H
extern Container LevelContainer;
extern UnicodeText LevelValue;

extern void setLevelContainer(int level);

extern void DrawLevelContainer();

#endif

#ifndef WINDOW_RESTART_H
extern Container restartButton;

extern void endGame();

extern void drawEndgameWindow();

extern void onClickRestartButton(Callback callback);

extern void onHoverStartButton();

#endif

#ifndef WINDOW_REWARD_H
extern Container rewardsContainer;
extern Container rewardBoard;
extern Container rewardLogo;
extern Container rewardBox;
extern int currReward;

extern void setRewardContainer(int level);

extern void drawRewardContainer();

#endif

#ifndef WINDOW_ASSISTANCE_H

extern Container assistanceContainer;
extern Assistance fiftyfiftyAssist;
extern Assistance plusOneAssist;
extern Assistance askExpertAssist;
//extern Assistance

extern void setAssistanceContainer(void);

extern void drawAssistanceContainer(void);

extern char plusOne(char correctAnswer);

extern char *fiftyFifty(char correctAnswer);

extern char askExpert(char correctAnswer);

#endif

#ifndef WINDOW_DIALOG_H

extern Dialog currentDialog;

extern void setDialog(Dialog *dialog, Rectangle rectangle, Rectangle button, char *content);

extern void DrawDialog();

#endif

// ----------------------Read files----------------------
char *readFile(const char *filename);

void readQuestions(cJSON *json_array, Question **questions, int *questions_count);

void saveData(Question **db, int *length, char *range);

// ----------------------Generate Question----------------------

int *generateQuestions(unsigned int lower_bound, unsigned int upper_bound);
// ----------------------Events----------------------

extern Rectangle *currentHoverRect;

void onEvents();

#ifdef __cplusplus
}
#endif

#endif // GAME_H