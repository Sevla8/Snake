#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include "coord.h"

typedef struct node S_node;
struct node {
	S_coord coord;
	node* next;
	node* prev;
};

#endif