#ifndef GAME_H
#define GAME_H

#include "defines.h"
#include "case.h"
#include "parameter.h"
#include "snake.h"
#include "tools.h"
#include "list.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <graph.h>

void init_snake(S_snake*, int, int, int);
void init_grid(E_case**, S_parameter, S_snake);
void print(S_snake, E_case**, int, int);
int change_direction(S_snake*);
void keep_moving(S_snake* snake);
int crash(S_snake, E_case**, int, int);
int eat_apple(S_snake*, E_case**, int, int);
void actualize_grid(S_snake*, E_case**, int, int);
void print_actualized_grid(S_snake, S_coord, E_case**, int, int);
void print_score(int, int, int);
void print_watch(char*, int, int);
void save_stats(int, int);
void stopNeat(S_snake*, E_case**, int, int);

#endif