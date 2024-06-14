#ifndef GAME_H
#define GAME_H

#include "../common.h"

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
    Container container;
    Answer answer;
};
typedef struct AnsContainer AnsContainer;

// ------------------------background------------------------
extern Container bgContainer;
// ------------------------------------------------

#ifndef WINDOW_QUESTION_H
extern UnicodeText questionContent;
extern Container questionContainer;
extern Container currQuest;
extern int currIndex;

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
extern AnsContainer AnsContainerA;
extern AnsContainer AnsContainerB;
extern AnsContainer AnsContainerC;
extern AnsContainer AnsContainerD;

void setAnswers();
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

#ifdef __cplusplus
}
#endif

#endif // GAME_H