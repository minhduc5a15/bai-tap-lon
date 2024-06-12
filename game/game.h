#ifndef GAME_H
#define GAME_H

#include "../common.h"
extern int *questions1_5;
extern int *questions6_10;
extern int *questions10_15;
extern Container bgContainer;
extern Container questionContainer;
extern Container *questionsData;
struct Question {
    char *content;
    char *answers[4];
    char *correct_answer;
};
typedef struct Question Question;
extern Question *questionDb;
extern Question currentQuestion;
extern UnicodeText questionContent;
extern int length;
extern int currentIndexQuestion;
#ifdef __cplusplus
extern "C" {
#endif

// ----------------------Background----------------------
void backgroundImageInit(void);

void setBackgroundImage(void);

// ----------------------Questions----------------------

void questionInit(void);

void setCurrentQuest(void);

// ----------------------Read files----------------------
char *read_file(const char *filename);

void read_questions(cJSON *json_array, Question **questions, int *questions_count);

void saveData(Question **db, int *length, char *range);

// ----------------------Generate Question----------------------

int *generateQuestions(unsigned int lower_bound, unsigned int upper_bound);

int getRandomQuestion(int begin, int end);

#ifdef __cplusplus
}
#endif

#endif // GAME_H