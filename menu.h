#ifndef MENU_H
#define MENU_H

#include <graph.h>
#include <stdlib.h>
#include "parameter.h"
#include "defines.h"
#include "start.h"

char* inttostr(int);

int screen_1(S_parameter*);
void screen_help();
int screen_2(S_parameter*);
int screen_3(S_parameter*);
int screen_4_1(S_parameter*);
int screen_4_2(S_parameter*);
int screen_4_3(S_parameter*);

#endif