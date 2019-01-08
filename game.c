#include "game.h"
#include <stdio.h>

void init_snake(S_snake* snake, int size, int width, int length) {

	snake->direction = RIGHT;
	snake->head = NULL;
	for (int i = 0; i < size; i += 1) {
		S_coord coord;
    	coord.x = width/2 - size/2 + i;
    	coord.y = length/2;
		snake->head = ajout_tete(snake->head, coord);
	}
}

void init_grid(E_case** grid, S_parameter parameter, S_snake snake) {

	for (int i = 0; i < parameter.gridWidth; i += 1) {
		E_case* subGrid = (E_case*) malloc(sizeof(E_case)*parameter.gridLength);
		*(grid+i) = subGrid;
	}

	for (int i = 0; i < parameter.gridWidth; i += 1) {
		for (int j = 0; j < parameter.gridLength; j += 1)
			grid[i][j] = GRASS;
	}

  	for (S_list* cur = snake.head; cur != NULL; cur = cur->next) {
		grid[cur->coord.x][cur->coord.y] = SNAKE;
	}

	for (int k = 0; k < parameter.appleAmount; ) {
	 	int i = rand() % parameter.gridWidth;
		int j = rand() % parameter.gridLength;
		if (grid[i][j] == GRASS) {
			grid[i][j] = APPLE;
			k += 1;
		}
	}

	for (int k = 0; k < parameter.barrierAmount; ) {
		int i = rand() % parameter.gridWidth;
		int j = rand() % parameter.gridLength;
		if (grid[i][j] == GRASS) {
			grid[i][j] = BARRIER;
			k += 1;
		}  		
	}
}

void print(S_snake snake, E_case** grid, int width, int length) {

	ChoisirEcran(5);
	EffacerEcran(CouleurParNom("green"));

  	for (int i = 0; i < width; i += 1) {
		for (int j = 0; j < length; j += 1) {
			if (grid[i][j] == APPLE) {
				ChoisirCouleurDessin(CouleurParNom("red"));
				RemplirArc(i*SIZE, j*SIZE, SIZE, SIZE, 0, 360);
 			}
 			else if (grid[i][j] == GRASS) {
 				ChoisirCouleurDessin(CouleurParNom("green"));
 				RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
 			}
 			else if (grid[i][j] == BARRIER) {
 				ChoisirCouleurDessin(CouleurParNom("grey"));
 				RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
 			}
 			else if (grid[i][j] == SNAKE) {
 				ChoisirCouleurDessin(CouleurParNom("yellow"));
				if (i == snake.head->coord.x && j == snake.head->coord.y) {
					if (snake.direction == RIGHT) 
						RemplirTriangle(i*SIZE, j*SIZE, i*SIZE, j*SIZE + SIZE, i*SIZE + SIZE, j*SIZE + SIZE/2);
					else if (snake.direction == LEFT) 
						RemplirTriangle(i*SIZE + SIZE, j*SIZE, i*SIZE + SIZE, j*SIZE + SIZE, i*SIZE, j*SIZE + SIZE/2);
					else if (snake.direction == UP) 
						RemplirTriangle(i*SIZE, j*SIZE + SIZE, i*SIZE + SIZE, j*SIZE + SIZE, i*SIZE + SIZE/2, j*SIZE);
					else if (snake.direction == DOWN) 
						RemplirTriangle(i*SIZE, j*SIZE, i*SIZE + SIZE, j*SIZE, i*SIZE + SIZE/2, j*SIZE + SIZE);
				}
				else
					RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
 			}
 		}
 	}

 	ChoisirEcran(0);
 	EffacerEcran(CouleurParNom("black"));
 	CopierZone(5, 0, 0, 0, width*SIZE, length*SIZE, MARGE, MARGE);
}

int change_direction(S_snake* snake) {

	if (SourisCliquee()) {

		if ((snake->direction == RIGHT || snake->direction == LEFT) && (_Y < snake->head->coord.y*SIZE+MARGE))
			snake->direction = UP;

		else if ((snake->direction == RIGHT || snake->direction == LEFT) && (_Y > snake->head->coord.y*SIZE+MARGE+SIZE))
			snake->direction = DOWN;
		
		else if ((snake->direction == UP || snake->direction == DOWN) && (_X < snake->head->coord.x*SIZE+MARGE)) 
			snake->direction = LEFT;

		else if ((snake->direction == UP || snake->direction == DOWN) && (_X > snake->head->coord.x*SIZE+MARGE+SIZE)) 
			snake->direction = RIGHT;

		else { //pour vider le buffer une fois qu'on est dans la direction voulu
			while (SourisCliquee())
				SourisCliquee();
		}
	}

	if (ToucheEnAttente()) {

		int T = Touche();

		if (T == XK_Right && snake->direction != LEFT && snake->direction != RIGHT)
			snake->direction = RIGHT;

		else if (T == XK_Left && snake->direction != RIGHT && snake->direction != LEFT)
			snake->direction = LEFT;

		else if (T == XK_Up && snake->direction != DOWN && snake->direction != UP)
			snake->direction = UP;

		else if (T == XK_Down && snake->direction != UP && snake->direction != DOWN)
			snake->direction = DOWN;

		else if (T == XK_space) {
			while (True) {
				if (ToucheEnAttente()) {
					int T = Touche();
					if (T == XK_space)
						break;
				}
			}
		}

		else if (T == XK_Escape) 
			return 1;

		else { //vider le buffer si par exemple on dirige le serpent en restant appuyé sur les touches
			while (ToucheEnAttente())
				Touche();
		}

		return 0;
	}
}

void keep_moving(S_snake* snake) {

	S_coord coord = snake->head->coord;

	if (snake->direction == RIGHT) {
		coord.x += 1;
	}
	else if (snake->direction == LEFT) {
		coord.x -= 1;
	}
	else if (snake->direction == UP) {
		coord.y -= 1;
	}
	else if (snake->direction == DOWN) {
		coord.y += 1;
	}

	snake->head = ajout_tete(snake->head, coord);
}

int crash(S_snake snake, E_case** grid, int width, int length) {

	if (snake.head->coord.x < 0 || snake.head->coord.y < 0 || snake.head->coord.x >= width || snake.head->coord.y >= length)
		return 1;

	if (grid[snake.head->coord.x][snake.head->coord.y] == BARRIER)
		return 1;

	for (S_list* cur = snake.head->next; cur->next != NULL; cur = cur->next) {
		if (snake.head->coord.x == cur->coord.x && snake.head->coord.y == cur->coord.y)
			return 1;
	}

	return 0;	
}

int eat_apple(S_snake* snake, E_case** grid, int width, int length) {

	int k = 0;

	while (grid[snake->head->coord.x][snake->head->coord.y] == APPLE) {

		grid[snake->head->coord.x][snake->head->coord.y] = GRASS;

		k += 1;
		
		S_coord coord = snake->head->coord;

		if (snake->direction == RIGHT) {
			coord.x += 1;
		}
		else if (snake->direction == LEFT) {
			coord.x -= 1;
		}
		else if (snake->direction == UP) {
			coord.y -= 1;
		}
		else if (snake->direction == DOWN) {
			coord.y += 1;
		}	

		snake->head = ajout_tete(snake->head, coord);

		if (crash(*snake, grid, width, length))
			return k;
	}

	return k;
}

void actualize_grid(S_snake* snake, E_case** grid, int width, int length) {

	S_list* cur;
	for (cur = snake->head; cur->next != NULL; cur = cur->next) {}
	grid[cur->coord.x][cur->coord.y] = GRASS;

	print_actualized_grid(*snake, cur->coord, grid, width, length);

	snake->head = supprimer_dernier(snake->head);

	for (S_list* cur = snake->head; cur != NULL; cur = cur->next) {
		if (grid[cur->coord.x][cur->coord.y] == GRASS) {
			grid[cur->coord.x][cur->coord.y] = SNAKE;
		}
		print_actualized_grid(*snake, cur->coord, grid, width, length);
	}

	CopierZone(5, 0, 0, 0, width*SIZE, length*SIZE, MARGE, MARGE);
}

void print_actualized_grid(S_snake snake, S_coord coord, E_case** grid, int width, int length) {

	ChoisirEcran(5);

	if (grid[coord.x][coord.y] == GRASS) {
		ChoisirCouleurDessin(CouleurParNom("green"));
		RemplirRectangle(coord.x*SIZE, coord.y*SIZE, SIZE, SIZE);
	}
	else if (grid[coord.x][coord.y] == SNAKE) {
		ChoisirCouleurDessin(CouleurParNom("yellow"));
		if (coord.x == snake.head->coord.x && coord.y == snake.head->coord.y) {
			if (snake.direction == RIGHT) 
				RemplirTriangle(coord.x*SIZE, coord.y*SIZE, coord.x*SIZE, coord.y*SIZE + SIZE, coord.x*SIZE + SIZE, coord.y*SIZE + SIZE/2);
			else if (snake.direction == LEFT) 
				RemplirTriangle(coord.x*SIZE + SIZE, coord.y*SIZE, coord.x*SIZE + SIZE, coord.y*SIZE + SIZE, coord.x*SIZE, coord.y*SIZE + SIZE/2);
			else if (snake.direction == UP) 
				RemplirTriangle(coord.x*SIZE, coord.y*SIZE + SIZE, coord.x*SIZE + SIZE, coord.y*SIZE + SIZE, coord.x*SIZE + SIZE/2, coord.y*SIZE);
			else if (snake.direction == DOWN) 
				RemplirTriangle(coord.x*SIZE, coord.y*SIZE, coord.x*SIZE + SIZE, coord.y*SIZE, coord.x*SIZE + SIZE/2, coord.y*SIZE + SIZE);
		}
		else
			RemplirRectangle(coord.x*SIZE, coord.y*SIZE, SIZE, SIZE);
	}
}

void print_score(int score, int width, int length) {

	ChoisirEcran(3);
	EffacerEcran(CouleurParNom("black"));
	ChoisirCouleurDessin(CouleurParNom("white"));

	int ysup = TailleSupPolice(2);
	int yinf = TailleInfPolice(2);
	int y = (ysup+yinf);

	int x = TailleChaineEcran(inttostr(score), 2);

	EcrireTexte(0, ysup, inttostr(score), 2);

	CopierZone(3, 0, 0, 0, x, y, width*SIZE+MARGE-x, length*SIZE+MARGE);
}

void print_watch(char* watch, int width, int length) {

	ChoisirEcran(4);
	EffacerEcran(CouleurParNom("black"));
	ChoisirCouleurDessin(CouleurParNom("white"));

	int ysup = TailleSupPolice(2);
	int yinf = TailleInfPolice(2);
	int y = (ysup+yinf);

	int x = TailleChaineEcran(watch, 2);

	EcrireTexte(0, ysup, watch, 2);

	CopierZone(4, 0, 0, 0, x, y, MARGE, length*SIZE+MARGE);	
}

void save_stats(int level, int score) {

	int lastLevel = open("level.txt", O_RDONLY);
	char prevLevel[10];
	memset(prevLevel, 0, 10);
	int rl = read(lastLevel, prevLevel, sizeof(char)*10);
	close(lastLevel);
	int levelx = strtoint(prevLevel);
	if (levelx < level) {
		int saveLevel = open("level.txt", O_WRONLY | O_CREAT | O_TRUNC);
		write(saveLevel, inttostr(level), sizeof(char)*strlength(inttostr(level)));
		close(saveLevel);
	}

	int lastScore = open("score.txt", O_RDONLY);
	char prevScore[10];
	memset(prevScore, 0, 10);
	int rs = read(lastScore, prevScore, sizeof(char)*10);
	close(lastScore);
	int scorex = strtoint(prevScore);
	if (scorex < score) {
		int saveScore = open("score.txt", O_WRONLY | O_CREAT | O_TRUNC);
		write(saveScore, inttostr(score), sizeof(char)*strlength(inttostr(score)));
		close(saveScore);
	}	
}

void stopNeat(S_snake* snake, E_case** grid, int width, int length) {
	grid[snake->head->next->coord.x][snake->head->next->coord.y] = SNAKE;
	print_actualized_grid(*snake, snake->head->next->coord, grid, width, length);
	print_actualized_grid(*snake, snake->head->next->next->coord, grid, width, length);
	S_list* cur;
	for (cur = snake->head; cur->next != NULL; cur = cur->next) {}
	grid[cur->coord.x][cur->coord.y] = GRASS;
	print_actualized_grid(*snake, cur->coord, grid, width, length);
	CopierZone(5, 0, 0, 0, width*SIZE, length*SIZE, MARGE, MARGE);
}