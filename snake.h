#ifndef SNAKE_H
#define SNAKE_H

#include "coord.h"
#include "direction.h"

struct snake {
	E_direction direction;
	int speed;
	int size;
	S_coord head;
	S_coord* body;
};

typedef struct snake S_snake;

#endif