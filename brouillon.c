#include "settings.h"
#include <graph.h>

int Settings(int* gridWidth, int* gridHeigth, int* appleAmount, int* snakeSize) {



    int x4 = TailleChaineEcran("Select field size", 2);
    int x5 = TailleChaineEcran("[20 x 30]     [40 x 60]     [60 x 90]     [80 x 120]", 1);
  	int x6 = TailleChaineEcran("Select Apple amount", 2);
  	int x7 = TailleChaineEcran("[3]     [5]     [8]     [10]", 1);
  	int x8 = TailleChaineEcran("Select Snake size", 2);
  	int x9 = TailleChaineEcran("[5]     [7]     [10]     [15]     [20]", 1);



	ChoisirEcran(4);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(250-x4/2, 150-y2/2, "Select field size", 2);
	EcrireTexte(250-x5/2, 250-y1/2, "[20 x 30]         [40 x 60]         [60 x 90]         [80 x 120]", 1);

	ChoisirEcran(5);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(250-x6/2, 150-y2/2, "Select Apple amount", 2);
	EcrireTexte(250-x7/2, 250-y1/2, "[3]     [5]     [8]     [10]", 1);

	ChoisirEcran(6);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(250-x8/2, 150-y2/2, "Select Snake size", 2);
	EcrireTexte(250-x9/2, 250-y1/2, "[5]     [7]     [10]     [15]     [20]", 1);

	ChoisirEcran(0);

	CopierZone(3, 0, 0, 0, 500, 500, 0, 0);

	// while (!SourisCliquee()) {}

	// while (1) {
	
	// 	SourisCliquee();

	// 	if (_X >= 250-x4 && _X <= 250+x4 && _Y >= 200-y2 && _Y <= 200+y2) {

	// 		CopierZone(4, 0, 0, 0, 500, 500, 0, 0);

	// 		while (1) {

	// 			SourisCliquee();

	// 			if (_X >= 250-x5 && _X <= 250-x5+x5/7 && _Y >= 250-y1 && _Y <= 250+y1) {

	// 				*gridHeigth = 20;
	// 				*gridWidth = 30;

	// 			}

	// 			else if () {

	// 				*gridHeigth = 40;
	// 				*gridWidth = 60;

	// 			}

	// 			else if () {

	// 				*gridHeigth = 60;
	// 				*gridWidth = 90;

	// 			}

	// 			else if () {

	// 				*gridHeigth = 80;
	// 				*gridWidth = 120;

	// 			}

	// 		}

	// 	}

	// 	else if (_X >= 250-x2 && _X <= 250+x2 && _Y >= 250-y2 && _Y <= 250+y2) {

	// 		CopierZone(5, 0, 0, 0, 500, 500, 0, 0);

	// 	}

	// 	else if (_X >= 250-x3 && _X <= 250+x3 && _Y >= 300-y2 && _Y <= 300+y2) {

	// 		CopierZone(6, 0, 0, 0, 500, 500, 0, 0);

	// 	}

	// }	

	// while (1) {}

	return 0;
}