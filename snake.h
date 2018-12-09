#ifndef SNAKE_H
#define SNAKE_H

#include "coord.h"

struct snake {
	Tcoord snake;
	int direction;
	int flow;
	int speed;
	int size;
	Tcoord head;
};

typedef struct snake Tsnake;

#endif
