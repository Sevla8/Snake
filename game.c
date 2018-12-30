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
		return game_over(parameter);
	}

	int s = snake.size;
	for (int i = 0; i < s; i += 1) {
		if (snake.body[i].x == snake.head.x && snake.body[i].y == snake.head.y) {
			return game_over(parameter);
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

int game_over(S_parameter* parameter){

	int y2sup = TailleSupPolice(2);
    int y2inf = TailleInfPolice(2);
    int y2 = (y2sup+y2inf)/2;
    int y1sup = TailleSupPolice(1);
    int y1inf = TailleInfPolice(1);
    int y1 = (y1sup+y1inf)/2;
    int y0sup = TailleSupPolice(0);
    int y0inf = TailleInfPolice(0);
    int y0 = (y0sup+y0inf)/2;

     int x = TailleChaineEcran("GAME OVER", 2);

    ChoisirEcran(1);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(gridWidth-x/2, gridLength-y2/2, "GAME OVER",2);

	CopierZone(1, 0, 0, 0, gridWidth, gridLength, 0, 0);

	unsigned long time = Microsecondes();

 	while(!(Microsecondes() > time + 10*SECONDE || ToucheEnAttente() || SourisCliquee())){}

	return screen_1(parameter);
}

/*void level_count(S_parameter* parameter, int next){

	int y2sup = TailleSupPolice(2);
    int y2inf = TailleInfPolice(2);
    int y2 = (y2sup+y2inf)/2;
    int y1sup = TailleSupPolice(1);
    int y1inf = TailleInfPolice(1);
    int y1 = (y1sup+y1inf)/2;

    int x = TailleChaineEcran("LEVEL", 2);
    int cursor;

    if (next == 1){
    	for(cursor=1; next==1 ; cursor=cursor+1){
    		
    		ChoisirEcran(1);
			EffacerEcran(CouleurParNom("black"));
			EcrireTexte(gridWidth-x/2, gridLength-y2/2, "LEVEL", 2);
			EcrireTexte(gridWidth-x/2+x, gridLength-y2/2, inttostr(cursor), 2);
    }
	
	CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
	unsigned long time = Microsecondes();

 	while(!(Microsecondes() > time + 3*SECONDE )){}

}
*/
