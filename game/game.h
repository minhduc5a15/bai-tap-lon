#ifndef GAME_H
#define GAME_H

#include "../common.h"
extern Container bgContainer;
extern Container currQuestion;
extern Container *questionsData;
extern struct Question;
#ifdef __cplusplus
extern "C" {
#endif
// ----------------------Background----------------------
void backgroundImageInit(void);

void setBackgroundImage(void);

// ----------------------Questions----------------------
void generateQuestions(void);

void questionInit(void);

void setCurrentQuest(void);

#ifdef __cplusplus
}
#endif

#endif // GAME_H