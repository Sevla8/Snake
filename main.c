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
  	CreerFenetre(50,50,500,500);
  	EffacerEcran(CouleurParNom("black"));
  	ChoisirCouleurDessin(CouleurParNom("white"));

  	//Menu();

  	ChoisirEcran(0);
  	EffacerEcran(CouleurParNom("green"));

  	// Tcase grille[40][60];

  	// for (int i = 0; i < 40; i = i+1) {
  	// 	for (int j = 0; j < 60; j = j+1) {
  	// 		grille[i][j] = grass;
  	// 	}
  	// }

  	// for (int i = 0; i < 40; i = i+1) {
  	// 	for (int j = 0; j < 60; j = j+1) {
  	// 		if (grille[i][j] == grass) {
  	// 			RemplirRectangle;
  	// 		}
  	// 	}
  	// }


	
	exit(0);
}