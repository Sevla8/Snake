#include <graph.h>
#include "parameter.h"
#include "menu.h"
#include "start.h"

int main(int argc, char* argv[]) {

  InitialiserGraphique();
	CreerFenetre(5,5,1000,1000);

	S_parameter parameter;
	parameter.gridWidth = 60;
	parameter.gridLength = 40;
	parameter.appleAmount = 5;
	parameter.barrierAmount = 0;
	parameter.snakeSize = 10;
	parameter.snakeSpeed = 1;

	//Menu(&parameters);

	Start(&parameter);

  FermerGraphique();

  return 0;
}