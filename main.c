#include <stdlib.h>
#include <graph.h>
#include "menu.h"
#include "settings.h"

int main(int argc, char* argv[]) {

	InitialiserGraphique();
  	CreerFenetre(50,50,500,500);
  	EffacerEcran(CouleurParNom("black"));
  	ChoisirCouleurDessin(CouleurParNom("white"));

  	Menu();


	
	exit(0);
}