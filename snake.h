#ifndef SNAKE_H
#define SNAKE_H

#include "coord.h"
#include "direction.h"
#include "list.h"

struct snake {
	E_direction direction;
	S_list* head;
};

typedef struct snake S_snake;

#endif