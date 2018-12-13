#include <graph.h>
#include "menu.h"
#include "start.h"

int main(int argc, char* argv[]) {

    InitialiserGraphique();
  	CreerFenetre(5,5,1000,1000);

  	int gridLength = 40, gridWidth = 60, appleAmount = 5, snakeSize = 10, barrierAmount = 0, snakeSpeed = 1;

  	//Menu(&gridLength, &gridWidth, &appleAmount, &snakeSize, &barrierAmount, &snakeSpeed);

  	Start(gridWidth, gridLength, appleAmount, snakeSize, barrierAmount, snakeSpeed);

    FermerGraphique();

	exit(0);
}