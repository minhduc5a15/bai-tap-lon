#include "game.h"

static char correctAns;

static const int dialogWidth = 450;
static const int dialogHeight = 200;
static const int buttonWidth = 100;
static const int buttonHeight = 50;

static void onClickFiftyFifty() {
    if (fiftyfiftyAssist.isUsed) return;
    fiftyfiftyAssist.isUsed = true;
    auto removeAnswers = fiftyFifty(correctAns);
    for (int i = 0; i < 2; ++i) {
        switch (removeAnswers[i]) {
            case 'A':
                ansContainerA.answer.value = newUnicodeText(DEFAULT_FONT, " ");
                break;
            case 'B':
                ansContainerB.answer.value = newUnicodeText(DEFAULT_FONT, " ");
                break;
            case 'C':
                ansContainerC.answer.value = newUnicodeText(DEFAULT_FONT, " ");
                break;
            case 'D':
                ansContainerD.answer.value = newUnicodeText(DEFAULT_FONT, " ");
                break;
            default:
                break;
        }
    }
    free(removeAnswers);
}

static void onClickPlusOne() {
    if (plusOneAssist.isUsed) return;
    Rectangle rect = {SCREEN_WIDTH / 2 - dialogWidth / 2, SCREEN_HEIGHT / 2 - dialogHeight / 2, dialogWidth, dialogHeight};
    Rectangle btnRect = {0, 0, buttonWidth, buttonHeight};
    char suggestedAnswer = plusOne(correctAns);
    char temp[2];
    temp[0] = suggestedAnswer;
    temp[1] = '\0';
    setDialog(&currentDialog, rect, btnRect, addStr("Bạn đồng hành gợi ý đáp án ", temp));
    currentDialog.isOpening = true;
    plusOneAssist.isUsed = true;
}

static void onClickAskExpert() {
    if (askExpertAssist.isUsed) return;
    Rectangle rect = {SCREEN_WIDTH / 2 - dialogWidth / 2, SCREEN_HEIGHT / 2 - dialogHeight / 2, dialogWidth, dialogHeight};
    Rectangle btnRect = {0, 0, buttonWidth, buttonHeight};
    char suggestedAnswer = askExpert(correctAns);
    char temp[2];
    temp[0] = suggestedAnswer;
    temp[1] = '\0';
    setDialog(&currentDialog, rect, btnRect, addStr("Các chuyên gia gợi ý đáp án ", temp));
    currentDialog.isOpening = true;
    askExpertAssist.isUsed = true;
}

static void onClose() {
    currentDialog.isOpening = false;
}

#ifndef CHOOSE_CORRECT_ANSWER

static void nextLevel() {
    showCorrectAnswer();
    setCurrLevel(getCurrLevel() + 1);
    setPassed(true);
    setIsSleeping(false);
    Sound s = LoadSound(CORRECT_ANSWER_SOUND);
    PlaySound(s);
}

static void chooseCorrectAnswer() {
    setIsSleeping(true);
    currentHoverRect = nullptr;
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    sleep(1);
    nextLevel();
}

static void nextQuestion() {
    chooseCorrectAnswer();
    setIsInit(false);
    setPassed(true);
}

#endif
#ifndef CHOOSE_WRONG_ANSWER

static void stop() {
    showCorrectAnswer();
    setPassed(true);
    setIsSleeping(false);
    Sound s = LoadSound(WRONG_ANSWER_SOUND);
    PlaySound(s);
}

static void chooseWrongAnswer() {
    setIsSleeping(true);
    currentHoverRect = nullptr;
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    sleep(1);
    stop();
}

static void lose() {
    chooseWrongAnswer();
    sleep(1);
    setEndgame(true);
    drawEndgameWindow();
}

#endif

static void restart() {
    setPassed(false);
    setCurrLevel(LEVEL_1);
    setEndgame(false);
    setIsInit(false);
    fiftyfiftyAssist.isUsed = false;
    askExpertAssist.isUsed = false;
    plusOneAssist.isUsed = false;
    currentDialog.isOpening = false;
    createDatabase();
}

static void start() {
    currentHoverRect = nullptr;
    setEndgame(false);
    setStarted(true);
    setIsInit(true);
    createDatabase();
    Sound s = LoadSound(START_SOUND);
    PlaySound(s);
}

void onEvents() {
    correctAns = currQuest.correctAnswer[0];
    if (currentHoverRect == nullptr) {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
#ifndef HOVER
    if (!getPassed()) {
        onHoverContainer(&ansContainerA.container, nullptr);
        onHoverContainer(&ansContainerB.container, nullptr);
        onHoverContainer(&ansContainerC.container, nullptr);
        onHoverContainer(&ansContainerD.container, nullptr);
        onHoverRect(currentDialog.okButton);
    }
#endif
#ifndef CLICK
    {
        onClickRect(fiftyfiftyAssist.container.destRect, onClickFiftyFifty);
        onClickRect(plusOneAssist.container.destRect, onClickPlusOne);
        onClickRect(askExpertAssist.container.destRect, onClickAskExpert);
        if (currentDialog.isOpening) {
            onClickRect(currentDialog.okButton, onClose);
        }
    }
    if (!getStarted()) {
        onHoverStartButton();
        onClickStartButton(start);
        return;
    }
    if (getEndgame()) {
        onClickRestartButton(restart);
        return;
    }
    if (currentHoverRect == &ansContainerA.container.destRect) {
        onClickContainer(ansContainerA.container, correctAns == 'A' ? nextQuestion : lose);
        return;
    }
    if (currentHoverRect == &ansContainerB.container.destRect) {
        onClickContainer(ansContainerB.container, correctAns == 'B' ? nextQuestion : lose);
        return;
    }
    if (currentHoverRect == &ansContainerC.container.destRect) {
        onClickContainer(ansContainerC.container, correctAns == 'C' ? nextQuestion : lose);
        return;
    }
    if (currentHoverRect == &ansContainerD.container.destRect) {
        onClickContainer(ansContainerD.container, correctAns == 'D' ? nextQuestion : lose);
        return;
    }
#endif
}