#include "start.h"

void Start(int gridWidth, int gridLength, int appleAmount, int snakeSize, int barrierAmount, int snakeSpeed) {

	  E_case** grid = (E_case**) malloc(sizeof(E_case*)*gridLength);

  	for (int i = 0; i < gridLength; i += 1) {
  		E_case* subGrid = (E_case*) malloc(sizeof(E_case)*gridWidth);
  		*(grid+i) = subGrid;
  	}

  	S_snake snake;
  	snake.direction = RIGHT;
  	snake.speed = snakeSpeed;
  	snake.size = snakeSize;
  	snake.body = (S_coord*) malloc(sizeof(S_coord)*snakeSize);
  	for (int i = 0; i < snakeSize; i += 1) {
  		snake.body[i].y = gridWidth/2 - snakeSize/2 + i;
  		snake.body[i].x = gridLength/2;
  	}
  	snake.head = snake.body[snakeSize-1];

  	for (int i = 0; i < gridLength; i += 1) {
  		  for (int j = 0; j < gridWidth; j += 1) {
  			    grid[i][j] = GRASS;
  		  }
  	}

  	for (int k = 0; k < snakeSize; k += 1) {
  		  grid[snake.body[k].x][snake.body[k].y] = SNAKE;
  	}

  	for (int k = 0; k < appleAmount; ) {
  	   	int i = rand() % gridLength;
  		int j = rand() % gridWidth;
  		if (grid[i][j] == GRASS) {	
  			grid[i][j] = APPLE;
  			k += 1;
  		}
  	}

  	for (int k = 0; k < barrierAmount; ) {
  		int i = rand() % gridLength;
  		int j = rand() % gridWidth;
  		if (grid[i][j] == GRASS) {
  			grid[i][j] = BARRIER;
  			k += 1;
  		}  		
  	}

  	
    print(grid, gridWidth, gridLength);

    while (1) {}
}