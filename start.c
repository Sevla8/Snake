#include "start.h"

void Start(S_parameter* parameter) {

	  E_case** grid = (E_case**) malloc(sizeof(E_case*)*parameter->gridWidth);

  	for (int i = 0; i < parameter->gridWidth; i += 1) {
  		E_case* subGrid = (E_case*) malloc(sizeof(E_case)*parameter->gridLength);
  		*(grid+i) = subGrid;
  	}

  	S_snake snake;
  	snake.direction = RIGHT;
  	snake.speed = parameter->snakeSpeed;
  	snake.size = parameter->snakeSize;
    // for (int i = 0; i < snakeSize; i += 1) {
    //   addTail();
    // }
    


  	snake.body = (S_coord*) malloc(sizeof(S_coord)*parameter->snakeSize);
  	for (int i = 0; i < parameter->snakeSize; i += 1) {
  		snake.body[i].x = parameter->gridWidth/2 - parameter->snakeSize/2 + i;
  		snake.body[i].y = parameter->gridLength/2;
  	}
  	snake.head = snake.body[parameter->snakeSize-1];

  	for (int i = 0; i < parameter->gridWidth; i += 1) {
  		  for (int j = 0; j < parameter->gridLength; j += 1) {
  			    grid[i][j] = GRASS;
  		  }
  	}

  	for (int k = 0; k < parameter->snakeSize; k += 1) {
  		  grid[snake.body[k].x][snake.body[k].y] = SNAKE;
  	}

  	for (int k = 0; k < parameter->appleAmount; ) {
  	   	int i = rand() % parameter->gridLength;
  		int j = rand() % parameter->gridWidth;
  		if (grid[i][j] == GRASS) {	
  			grid[i][j] = APPLE;
  			k += 1;
  		}
  	}

  	for (int k = 0; k < parameter->barrierAmount; ) {
  		int i = rand() % parameter->gridLength;
  		int j = rand() % parameter->gridWidth;
  		if (grid[i][j] == GRASS) {
  			grid[i][j] = BARRIER;
  			k += 1;
  		}  		
  	}

  	unsigned long time = Microsecondes();

    while (True) {

      if (Microsecondes() >= time + 1) {
        time = Microsecondes();
        actualize_grid(grid, snake);
        print(grid, parameter->gridWidth, parameter->gridLength);
        change_direction(&snake);
        keep_moving(&snake, grid);
        eat_apple(&snake, grid);
      }
    }
}