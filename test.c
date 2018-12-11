#include <stdlib.h>
#include <graph.h>
#include <time.h>

int main(int argc, char* argv[]) {

	enum Case {
		grass,
		snake,
		apple,
		barrier
	};

	typedef enum Case Tcase;

	struct coord {
		int x;
		int y;
	};

	typedef struct coord Tcoord;

	int tailleCase = 5;

	int longueur = 40 * tailleCase;
	int largeur = 60 * tailleCase;

	InitialiserGraphique();
	CreerFenetre(50, 50, longueur, largeur);
	ChoisirEcran(0);
  	EffacerEcran(CouleurParNom("green"));

  	Tcase** grille = (Tcase**) malloc(sizeof(Tcase*)*40);

  	int k = 0;
  	for (int i = 0; i < 40; i = i+1) {
  		Tcase* sousgrille = (Tcase*) malloc(sizeof(Tcase)*60);
  		*(grille+k) = sousgrille;
  		k = k+1;
  	}

  	for (int i = 0; i < 40; i = i+1) {
  		for (int j = 0; j < 60; j = j+1) {
  			grille[i][j] = grass;
  		}
  	}

  	for (int i = 0; i < 5; i = i+1) {
  		int a = rand() % 40;
  		int b = rand() % 60;
  		grille[a][b] = apple;
	}

	for (int i = 0; i < 10; i = i+1) {
  		grille[20+i][30] = snake;
	}

	

  	for (int i = 0; i < 40; i = i+1) {
  		for (int j = 0; j < 60; j = j+1) {
  			if (grille[i][j] == apple) {
  				ChoisirCouleurDessin(CouleurParNom("red"));
  				RemplirRectangle(i*tailleCase, j*tailleCase, tailleCase, tailleCase);
  			}
  			else if (grille[i][j] == grass) {
  				ChoisirCouleurDessin(CouleurParNom("green"));
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

    // Tcoord pomme;
  	// pomme.x = 10;
  	// pomme.y = 10;
  	// ChoisirCouleurDessin(CouleurParNom("red"));
  	// RemplirRectangle(pomme.x, pomme.y, tailleCase, tailleCase);

	while(1){}

	exit(0);

}