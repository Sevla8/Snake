#include "start.h"

int Start(int gridWidth, int gridLength, int appleAmount, int snakeSize, int barrierAmount, int snakeSpeed) {

	E_case** grid = (E_case**) malloc(sizeof(E_case*)*gridLength);

  	for (int i = 0, int k = 0; i < 40; i = i+1, k ) {
  		E_case* subGrid = (E_case*) malloc(sizeof(E_case)*gridWidth);
  		*(grid+i) = subGrid;
  	}

  	S_snake snake;
  	snake.direction = RIGHT;
  	snake.speed = snakeSpeed;
  	snake.size = snakeSize;
  	snake.body = (S_coord*) malloc(sizeof(S_coord)*snakeSize);
  	for (int i = 0; i < snakeSize; i = i+1) {
  		snake.body[i].x = gridWidth/2 - snakeSize/2 + i;
  		snake.body[i].y = gridLength/2;
  	}
  	snake.head = snake.body[snakeSize-1];

  	for (int i = 0; i < gridLength; i = i+1) {
  		for (int j = 0; j < gridWidth; j = j+1) {
  			grid[i][j] = GRASS;
  		}
  	}

  	int k1 = 0;
  	while (k1 < snakeSize) {
  		grid[snake[k1].x][snake[k1].y] = SNAKE;
  		k1 += 1;
  	}

  	int k2 = 0;
  	while (k2 < appleAmount) {
  		int i = rand() % gridLength;
  		int j = rand() % gridWidth;
  		if (grid[i][j] == GRASS) {	
  			grid[i][j] = APPLE;
  			k2 += 1;
  		}
  	}

  	int k3 = 0;
  	while (k3 < barrierAmount) {
  		int i = rand() % gridLength;
  		int j = rand() % gridWidth;
  		if (grid[i][j] == GRASS) {
  			grid[i][j] = BARRIER;
  			k3 += 1;
  		}  		
  	}

  	  	

	exit(0);
}

