#ifndef GAME_H
#define GAME_H

#include "case.h"
#include "snake.h"
#include "defines.h"
#include <stdlib.h>
#include <graph.h>

int print(E_case**, int, int);
int keep_moving(S_snake*, E_case**);
int change_direction(S_snake*);
int crash(S_snake, E_case);
int eat_apple(S_snake, E_case);

#endif
