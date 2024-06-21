#ifndef WINDOW_DIALOG_H
#define WINDOW_DIALOG_H

#include "../common.h"

Dialog currentDialog;

void setDialog(Dialog *dialog, Rectangle rectangle, Rectangle button, char *content);

void DrawDialog();

#endif // WINDOW_DIALOG_H