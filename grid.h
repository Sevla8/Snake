#ifndef GRID_H
#define GRID_H

#include "snake.h"
#include "coord.h"
#include "square.h"

struct grid {
	Tsquare** grid;
	Tcoord apple;
	Tcoord obstacle;
	Tsnake snake;
};

typedef struct grid Tgrid;

#endif