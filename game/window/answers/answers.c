#include "./answers.h"

extern AnsContainer AnsContainerA;
extern AnsContainer AnsContainerB;
extern AnsContainer AnsContainerC;
extern AnsContainer AnsContainerD;

void setAnswers() {
    AnsContainerA.container = currQuest;
    AnsContainerA.answer = questionDb[currIndex].answers[0];
    AnsContainerB.answer = questionDb[currIndex].answers[1];
    AnsContainerC.answer = questionDb[currIndex].answers[2];
    AnsContainerD.answer = questionDb[currIndex].answers[3];
}

