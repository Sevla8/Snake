#ifndef GAME_H
#define GAME_H

#include "case.h"
#include "snake.h"
#include "defines.h"
#include "game.h"
#include <stdlib.h>
#include <graph.h>

void print(E_case**, int, int);
void keep_moving(S_snake*, E_case**);
void change_direction(S_snake*);
int crash(S_snake, E_case**);
void eat_apple(S_snake*, E_case**);

#endif