#include "game.h"

int print(E_case** grid, int length, int width) {

	ChoisirEcran(1);

  	for (int i = 0; i < length; i = i+1) {
		for (int j = 0; j < width; j = j+1) {
			if (grid[i][j] == APPLE) {
				ChoisirCouleurDessin(CouleurParNom("red"));
 				RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
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
 				ChoisirCouleurDessin(CouleurParNom("brown"));
 				RemplirRectangle(i*SIZE, j*SIZE, SIZE, SIZE);
 			}
 		}
 	}

 	CopierZone(1, 0, 0, 0, heigth*SIZE, width*SIZE, 0, 0);

  	exit(0);
}

int keep_moving(S_snake* snake, E_case** grid) {

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

	for (int i = 0; i < snake->size-1; i = i+1) {
		snake->body[i] = snake->body[i+1];
	}
	snake->body[snake->size-1] = snake->head;

	exit(0);
}

int change_direction(S_snake* snake) {

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
	}
	exit(0);
}

int crash(S_snake snake, E_case** grid) {

	if (grid[snake->head.x][snake->head.y] == BARRIER) {
		return 1;
	}

	int s = snake->size;
	for (int i = 0; i < s; i = i+1) {
		for (int j = 0; j < s; j = j+1) {
			if (snake->body[i] == snake->body[j]) {
				return 1;
			}
		}
	}

	//serpent sort du terrain

	return 0;
}

int eat_apple(S_snake* sanke, E_case grid) {

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
	exit(0);
}