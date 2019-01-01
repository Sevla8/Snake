#ifndef GAME_H
#define GAME_H

#include "defines.h"
#include "case.h"
#include "parameter.h"
#include "snake.h"
#include "tools.h"
#include "list.h"
#include <graph.h>

void print(E_case**, int, int);
void change_direction(S_snake*);
void keep_moving(S_snake* snake);
int crash(S_snake, E_case**, int, int);
int eat_apple(S_snake*, E_case**);
void actualize_grid(S_snake*, E_case**, int, int);
void print_actualized_grid(S_coord, E_case**);
void print_score(int, int, int);

#endif