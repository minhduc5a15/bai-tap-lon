#ifndef WINDOW_QUESTION_H
#define WINDOW_QUESTION_H

#include "../common.h"

Question newQuestion(char *content, Answer answers[], const char *correctAnswer);

void getCurrentQuest(int level);

void drawQuestion(void);

#endif
