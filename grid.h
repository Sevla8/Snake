#ifndef GRID_H
#define GRID_H

struct grid {
	Tsquare** grid;
	Tcoord apple;
	Tcoord obstacle;
	Tsnake snake;
};

typedef struct grid Tgrid;

#endif