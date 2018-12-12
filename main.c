#include <stdlib.h>
#include <graph.h>
#include "defines.h"
#include "coord.h"
#include "case.h"
#include "snake.h"
#include "player.h"
#include "menu.h"
#include "settings.h"
#include "game.h"

int main(int argc, char* argv[]) {

    InitialiserGraphique();
  	CreerFenetre(5,5,1000,1000);
  	EffacerEcran(CouleurParNom("black"));
  	ChoisirCouleurDessin(CouleurParNom("white"));

  	Menu();

    FermerGraphique();

	  exit(0);
}