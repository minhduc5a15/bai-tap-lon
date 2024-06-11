#ifndef GAME_H
#define GAME_H

#include "../common.h"
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

void saveData(Question **db, int *length);

// ----------------------Generate Question----------------------

void generateQuestions(int begin, int end);

int getRandomQuestion(int begin, int end);

#ifdef __cplusplus
}
#endif

#endif // GAME_H