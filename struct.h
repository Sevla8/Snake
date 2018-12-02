#include <stdlib.h>
#include <graph.h>

struct coord {
	int x;
	int y;
};

typedef struct coord Tcoord;

struct square {
	Tcoord square[10*10];
};

typedef struct square Tsquare;

struct snake {
	Tsquare snake[500*500];
};

typedef struct snake Tsnake;

struct grid {
	Tcoord grid[500*500];
};

typedef struct grid Tgrid;