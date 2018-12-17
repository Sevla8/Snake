#include "game.h"

void print(E_case** grid, int width, int length) {

	ChoisirEcran(1);

  	for (int i = 0; i < width; i += 1) {
		for (int j = 0; j < length; j += 1) {
			if (grid[i][j] == APPLE) {
				ChoisirCouleurDessin(CouleurParNom("red"));
 				RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
 			}
 			else if (grid[i][j] == GRASS) {
 				ChoisirCouleurDessin(CouleurParNom("green"));
 				RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
 			}
 			else if (grid[i][j] == BARRIER) {
 				ChoisirCouleurDessin(CouleurParNom("black"));
 				RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
 			}
 			else if (grid[i][j] == SNAKE) {
 				ChoisirCouleurDessin(CouleurParNom("yellow"));
 				RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
 			}
 		}
 	}

 	CopierZone(1, 0, 0, 0, width*SIZE, length*SIZE, 0, 0);
}

void keep_moving(S_snake* snake, E_case** grid) {

	if (snake->direction == RIGHT) {
		snake->head.x += 1;
	}
	else if (snake->direction == LEFT) {
		snake->head.x -= 1;
	}
	else if (snake->direction == UP) {
		snake->head.y -= 1;
	}
	else if (snake->direction == DOWN) {
		snake->head.y += 1;
	}

	for (int i = 0; i < snake->size - 1; i += 1) {
		snake->body[i] = snake->body[i+1];
	}
	snake->body[snake->size-1] = snake->head;
}

void change_direction(S_snake* snake) {

	if (ToucheEnAttente()) {
		
		int T = Touche();
		
		if (T == XK_Right && snake->direction != LEFT) {
			snake->direction = RIGHT;
		}
		else if (T == XK_Left && snake->direction != RIGHT) {
			snake->direction = LEFT;
		}
		else if (T == XK_Up && snake->direction != DOWN) {
			snake->direction = UP;
		}
		else if (T == XK_Down && snake->direction != UP) {
			snake->direction = DOWN;
		}
		else if (T == XK_space)
			while (True) {
				if (ToucheEnAttente()) {
					int T = Touche();
					if (T == XK_space)
						break;
				}
			}
	}
}

int crash(S_snake snake, E_case** grid) {

	if (grid[snake.head.x][snake.head.y] == BARRIER) {
		return 1;
	}

	int s = snake.size;
	for (int i = 0; i < s; i += 1) {
		if (snake.body[i].x == snake.head.x && snake.body[i].y == snake.head.y) {
			return 1;
		}
	}

	// if (snake.head.x < 0 || snake.head.x > )
	// 	return 1;

	return 0;
}

void eat_apple(S_snake* snake, E_case** grid) {

	if (grid[snake->head.x][snake->head.y] == APPLE) {

		snake->size += 1;

		snake->body = (S_coord*) realloc(snake->body, sizeof(S_coord)*snake->size);

		if (snake->direction == RIGHT) {
			snake->head.x += 1;
		}
		else if (snake->direction == LEFT) {
			snake->head.x -= 1;
		}
		else if (snake->direction == UP) {
			snake->head.y -= 1;
		}
		else if (snake->direction == DOWN) {
			snake->head.y += 1;
		}	

		snake->body[snake->size-1] = snake->head;
	}
}

void actualize_grid(E_case** grid, S_snake snake) {

	grid[snake.body[0].x][snake.body[0].y] = GRASS;
	grid[snake.head.x][snake.head.y] = SNAKE;
	grid[snake.body[snake.size-2].x][snake.body[snake.size-2].y] = SNAKE;
}