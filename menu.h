#ifndef MENU_H
#define MENU_H

#include <graph.h>
#include <stdlib.h>
#include "parameter.h"
#include "player.h"
#include "defines.h"
#include "start.h"
#include "tools.h"

int screen_1();
void screen_help();
int screen_2(S_parameter*, S_player*);
int screen_3(S_parameter*, S_player*);
int screen_4_1(S_parameter*, S_player*);
int screen_4_2(S_parameter*, S_player*);
int screen_4_3(S_parameter*, S_player*);
void screen_lose(int, int, int, int);
void screen_levelUp(int, int, int);

#endif