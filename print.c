#include "print.h"

void print(Tcase** grille, int heigth, int width) {

	ChoisirEcran(1);

	for (int i = 0; i < heigth; i = i+1) {
  		for (int j = 0; j < width; j = j+1) {
  			if (grille[i][j] == apple) {
  				ChoisirCouleurDessin(CouleurParNom("red"));
  				RemplirRectangle(i*tailleCase, j*tailleCase, tailleCase, tailleCase);
  			}
  			else if (grille[i][j] == grass) {
  				ChoisirCouleurDessin(CouleurParNom("red"));
  				RemplirRectangle(i*tailleCase, j*tailleCase, tailleCase, tailleCase);
  			}
  			else if (grille[i][j] == barrier) {
  				ChoisirCouleurDessin(CouleurParNom("grey"));
  				RemplirRectangle(i*tailleCase, j*tailleCase, tailleCase, tailleCase);
  			}
  			else if (grille[i][j] == snake) {
  				ChoisirCouleurDessin(CouleurParNom("brown"));
  				RemplirRectangle(i*tailleCase, j*tailleCase, tailleCase, tailleCase);
  			}
  		}
  	}

  	CopierZone(1, 0, 0, 0, heigth*SIZE, width*SIZE, 0, 0);
}