#include "game.h"

void print(E_case** grid, int width, int length) {

	ChoisirEcran(1);
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
 				ChoisirCouleurDessin(CouleurParNom("brown"));
 				RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
 			}
 			else if (grid[i][j] == SNAKE) {
 				ChoisirCouleurDessin(CouleurParNom("yellow"));
 				RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
 			}
 		}
 	}

 	ChoisirEcran(0);
 	EffacerEcran(CouleurParNom("black"));
 	CopierZone(1, 0, 0, 0, width*SIZE, length*SIZE, MARGE, MARGE);
}

void change_direction(S_snake* snake) {

	if (SourisCliquee()) {

		if ((snake->direction == RIGHT || snake->direction == LEFT) && (_Y < snake->head->coord.y*SIZE+MARGE))
			snake->direction = UP;

		else if ((snake->direction == RIGHT || snake->direction == LEFT) && (_Y > snake->head->coord.y*SIZE+MARGE+SIZE))
			snake->direction = DOWN;
		
		else if ((snake->direction == UP || snake->direction == DOWN) && (_X < snake->head->coord.x*SIZE+MARGE)) 
			snake->direction = LEFT;

		else if ((snake->direction == UP || snake->direction == DOWN) && (_X > snake->head->coord.x*SIZE+MARGE+SIZE)) 
			snake->direction = RIGHT;
	}

	if (ToucheEnAttente()) {

		int T = Touche();

		if (T == XK_Right && snake->direction != LEFT)
			snake->direction = RIGHT;

		else if (T == XK_Left && snake->direction != RIGHT)
			snake->direction = LEFT;

		else if (T == XK_Up && snake->direction != DOWN)
			snake->direction = UP;

		else if (T == XK_Down && snake->direction != UP)
			snake->direction = DOWN;

		// else if (T == XK_space) {
		// 	while (True) {
		// 		if (ToucheEnAttente()) {
		// 			int T = Touche();
		// 			if (T == XK_space)
		// 				break;
		// 		}
		// 	}
		// }
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

	for (S_list* cur = snake.head->next; cur != NULL; cur = cur->next) {
		if (snake.head->coord.x == cur->coord.x && snake.head->coord.y == cur->coord.y)
			return 1;
	}

	return 0;	
}

int eat_apple(S_snake* snake, E_case** grid) {

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
	}

	return k;
}

void actualize_grid(S_snake* snake, E_case** grid, int width, int length) {

	if (!crash(*snake, grid, width, length)) {

		S_list* cur;
		for (cur = snake->head; cur->next != NULL; cur = cur->next) {}
		grid[cur->coord.x][cur->coord.y] = GRASS;

		print_actualized_grid(cur->coord, grid);

		snake->head = supprimer_dernier(snake->head);

		for (S_list* cur = snake->head; cur != NULL; cur = cur->next) {
			if (grid[cur->coord.x][cur->coord.y] == GRASS) {
				grid[cur->coord.x][cur->coord.y] = SNAKE;
				print_actualized_grid(cur->coord, grid);
			}
		}
	}

	else {
		snake->head = snake->head->next;
		actualize_grid(snake, grid, width, length);
	}
}

void print_actualized_grid(S_coord coord, E_case** grid) {

	ChoisirEcran(1);

	if (grid[coord.x][coord.y] == GRASS) {
		ChoisirCouleurDessin(CouleurParNom("green"));
		RemplirRectangle(coord.x*SIZE, coord.y*SIZE, SIZE, SIZE);
	}
	else if (grid[coord.x][coord.y] == SNAKE) {
		ChoisirCouleurDessin(CouleurParNom("yellow"));
		RemplirRectangle(coord.x*SIZE, coord.y*SIZE, SIZE, SIZE);
	}

	CopierZone(1, 0, coord.x*SIZE, coord.y*SIZE, SIZE, SIZE, MARGE+coord.x*SIZE, MARGE+coord.y*SIZE);
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