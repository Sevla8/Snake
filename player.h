#ifndef PLAYER_H
#define PLAYER_H 

struct player {
	unsigned long score;
	int level;
	char watch[6];
};

typedef struct player S_player;

#endif