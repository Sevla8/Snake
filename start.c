#include "start.h"

int start(S_parameter* parameter, S_player* player) {

  	srand(time(NULL));

	FermerGraphique();
  	InitialiserGraphique();
  	CreerFenetre(10,10,parameter->gridWidth*SIZE+MARGE*2, parameter->gridLength*SIZE+MARGE+5*MARGE);

	S_snake snake;
	init_snake(&snake, parameter->snakeSize, parameter->gridWidth, parameter->gridLength);

	E_case** grid = (E_case**) malloc(sizeof(E_case*)*parameter->gridWidth);
	init_grid(grid, *parameter, snake);

	screen_levelUp(player->level, parameter->gridWidth*SIZE + MARGE, parameter->gridLength*SIZE + 6*MARGE);

	print(snake, grid, parameter->gridWidth, parameter->gridLength);
	print_score(player->score, parameter->gridWidth, parameter->gridLength);
	print_watch(player->watch, parameter->gridWidth, parameter->gridLength);

	unsigned long t0 = Microsecondes();
	unsigned long time = Microsecondes();
	int stop = 0; 
	int esc = 0;
	int eat = 0;
	int nbApple = parameter->appleAmount;

  	//vidage buffer clavier & souris
	while (ToucheEnAttente())
  		Touche();
  	while (SourisCliquee())
    	SourisCliquee();

	while (!stop && nbApple && !esc) {

		if (Microsecondes() >= time + parameter->snakeSpeed) {
  	
	  		time = Microsecondes();

	  		esc = change_direction(&snake);
		  	keep_moving(&snake);
		  	stop = crash(snake, grid, parameter->gridWidth, parameter->gridLength);
		  	if (!stop) {
		  		eat = eat_apple(&snake, grid, parameter->gridWidth, parameter->gridLength);
			  	player->score += SCORE*eat;
				nbApple -= eat;
	        	stop = crash(snake, grid, parameter->gridWidth, parameter->gridLength);
	        	if (!stop)
			  		actualize_grid(&snake, grid, parameter->gridWidth, parameter->gridLength);
			  	if (eat)
			  		print_score(player->score, parameter->gridWidth, parameter->gridLength);
				if (stop && eat) { 
					stopNeat(&snake, grid, parameter->gridWidth, parameter->gridLength);
					unsigned long x = Microsecondes();				//pour que l'on voit bien qu'il y a eu
					while (Microsecondes() < x + SECONDE/10) {}		//eat avant crash, sinon trop rapide.
		  		}
			}
		}

		if (Microsecondes() >= t0 + SECONDE) {
			t0 = Microsecondes();
			player->watch[4] = (char) ((int) player->watch[4] + 1);
			if (player->watch[4] == ':')
				player->watch[4] = '0';
			if (player->watch[4] == '0')
				player->watch[3] = (char) ((int) player->watch[3] + 1);
			if (player->watch[3] == '6')
				player->watch[3] = '0';
			if (player->watch[4] == '0' && player->watch[3] == '0')
				player->watch[1] = (char) ((int) player->watch[1] + 1);
			if (player->watch[1] == ':')
				player->watch[1] = '0';
			if (player->watch[4] == '0' && player->watch[3] == '0' && player->watch[1] == '0')
				player->watch[0] = (char) ((int) player->watch[0] + 1);
			if (player->watch[0] == '6')
				player->watch[0] = '0';
			print_watch(player->watch, parameter->gridWidth, parameter->gridLength);
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
		parameter->snakeSpeed = parameter->snakeSpeed * COEFF;
		return start(parameter, player);
	}

	if (stop || esc) {
    	save_stats(player->level, player->score);
		screen_lose(parameter->gridWidth*SIZE + MARGE, parameter->gridLength*SIZE + 6*MARGE, player->score, player->level);
		FermerGraphique();
		return screen_1();
	}
}
