#ifndef WINDOW_ASSISTANCE_H
#define WINDOW_ASSISTANCE_H

#include "../common.h"

Container assistanceContainer;
Assistance fiftyfiftyAssist;
Assistance plusOneAssist;
Assistance askExpertAssist;

void setAssistanceContainer(void);

void drawAssistanceContainer(void);

char plusOne(char correctAnswer);

char *fiftyFifty(char correctAnswer);

char askExpert(char correctAnswer);

#endif // WINDOW_ASSISTANCE_H