#include "start.h"

int start(S_parameter* parameter, S_player* player) {

	srand(time(NULL));

	FermerGraphique();
    InitialiserGraphique();
    CreerFenetre(10,10,parameter->gridWidth*SIZE+MARGE*2, parameter->gridLength*SIZE+MARGE+5*MARGE);

    E_case** grid = (E_case**) malloc(sizeof(E_case*)*parameter->gridWidth);

  	for (int i = 0; i < parameter->gridWidth; i += 1) {
  		E_case* subGrid = (E_case*) malloc(sizeof(E_case)*parameter->gridLength);
  		*(grid+i) = subGrid;
  	}

  	S_snake snake;
  	snake.direction = RIGHT;

  	snake.head = NULL;
  	for (int i = 0; i < parameter->snakeSize; i += 1) {
  		S_coord coord;
      	coord.x = parameter->gridWidth/2 - parameter->snakeSize/2 + i;
      	coord.y = parameter->gridLength/2;
  		snake.head = ajout_tete(snake.head, coord);
  	}

  	for (int i = 0; i < parameter->gridWidth; i += 1) {
  		for (int j = 0; j < parameter->gridLength; j += 1)
  			grid[i][j] = GRASS;
  	}

	for (S_list* cur = snake.head; cur != NULL; cur = cur->next) {
  		grid[cur->coord.x][cur->coord.y] = SNAKE;
  	}

  	for (int k = 0; k < parameter->appleAmount; ) {
  	   	int i = rand() % parameter->gridWidth;
  		int j = rand() % parameter->gridLength;
  		if (grid[i][j] == GRASS) {
  			grid[i][j] = APPLE;
  			k += 1;
  		}
  	}

  	for (int k = 0; k < parameter->barrierAmount; ) {
  		int i = rand() % parameter->gridWidth;
  		int j = rand() % parameter->gridLength;
  		if (grid[i][j] == GRASS) {
  			grid[i][j] = BARRIER;
  			k += 1;
  		}  		
  	}

  	screen_levelUp(player->level, parameter->gridWidth*SIZE + MARGE, parameter->gridLength*SIZE + 6*MARGE);

  	print(grid, parameter->gridWidth, parameter->gridLength);

  	print_score(player->score, parameter->gridWidth, parameter->gridLength);

  	unsigned long time = Microsecondes();
  	int stop = 0;
  	int nbApple = parameter->appleAmount;

  	while (!stop && nbApple) {

  		if (Microsecondes() >= time + parameter->snakeSpeed) {
    	
    		time = Microsecondes();

    		change_direction(&snake);
		  	keep_moving(&snake);
		  	stop = crash(snake, grid, parameter->gridWidth, parameter->gridLength);
		  	if (!stop) {
		  		int eat = eat_apple(&snake, grid);
			  	player->score += SCORE*eat;
				nbApple -= eat;
			  	actualize_grid(&snake, grid, parameter->gridWidth, parameter->gridLength);
			  	if (eat)
			  		print_score(player->score, parameter->gridWidth, parameter->gridLength);
		  	}
		}
	}

	for (int i = 0; i < parameter->gridWidth; i += 1)
		free(grid[i]);
	free(grid);
	for (S_list* cur = snake.head; cur != NULL; cur = cur->next)
		free(cur);

	if (!nbApple) {
		player->level += 1;
		parameter->barrierAmount += 1;
		parameter->appleAmount += 1;
		parameter->snakeSpeed /= 2;
		start(parameter, player);
	}

	if (stop == 1) {
		screen_lose(parameter->gridWidth*SIZE + MARGE, parameter->gridLength*SIZE + 6*MARGE, player->score, player->level);
		FermerGraphique();
		screen_1();
	}
}