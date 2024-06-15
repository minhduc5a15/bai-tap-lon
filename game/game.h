#ifndef GAME_H
#define GAME_H

#include "../common.h"
// -------------------Global Variables --------------------------------

extern int currLevel;
extern bool running;
extern Container *currentClickContainer;
extern char *currAnswer;

void setRunning(bool value);

bool getRunning();

void *setCurrentClickContainer(void *container);

void *getCurrentClickContainer();

void setCurrLevel(int value);

int getCurrLevel();

void setCurrAnswer(char *answer);

char *getCurrAnswer();

// ----------------------------------------------------------------

struct Answer {
    char *answer; // A, B, C or D
    UnicodeText value;
    bool isCorrect;
};
typedef struct Answer Answer;

struct Question {
    char *content;
    Answer answers[4];
    char *correctAnswer;
};
typedef struct Question Question;

struct AnsContainer {
    Answer answer;
    Container container;
};
typedef struct AnsContainer AnsContainer;

// ------------------------background------------------------
extern Container bgContainer;
// ------------------------------------------------
extern bool check;
#ifndef WINDOW_QUESTION_H
extern UnicodeText questionContent;
extern Container questionContainer;
extern Container currQuest;

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

extern void setBackgroundImage(void);

// ----------------------Questions----------------------

extern void questionInit(void);

extern void setCurrentQuest(void);

// ----------------------Read files----------------------
char *readFile(const char *filename);

void readQuestions(cJSON *json_array, Question **questions, int *questions_count);

void saveData(Question **db, int *length, char *range);

// ----------------------Generate Question----------------------

int *generateQuestions(unsigned int lower_bound, unsigned int upper_bound);
// ----------------------Events----------------------

extern bool isHovering;
extern Container *currentHoverContainer;

void onEvents();


#ifdef __cplusplus
}
#endif

#endif // GAME_H