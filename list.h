#ifndef list_H
#define list_H

#include "coord.h"

typedef struct list S_list;
struct list {
	S_coord coord;
	S_list* next;
	S_list* prev;
};

#endif