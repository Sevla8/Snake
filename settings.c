#include "settings.h"

void Settings() {

    int y2sup = TailleSupPolice(2);
    int y2inf = TailleInfPolice(2);
    int y2 = (ysup+yinf)/2;
    int y1sup = TailleSupPolice(1);
    int y1inf = TailleInfPolice(1);
    int y1 = (ysup+yinf)/2;
    int x1 = TailleChaineEcran("Field Size", 1)/2;
  	int x2 = TailleChaineEcran("Apple amount", 1)/2;
  	int x3 = TailleChaineEcran("Snake size", 1)/2;
    int x4 = TailleChaineEcran("Select field size", 1)/2;
    int x5 = TailleChaineEcran("20 x 30   40 x 60   60 x 90   80 x 120", 1)/2;
  	int x6 = TailleChaineEcran("Select Apple amount", 1)/2;
  	int x7 = TailleChaineEcran("3   5   8   10", 1)/2;
  	int x8 = TailleChaineEcran("Select Snake size")/2;
  	int x9 = TailleChaineEcran("5   7   10   15   20")/2;

	ChoisirEcran(3);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(250-x1, 200-y2, "Field Size", 2);
	EcrireTexte(250-x2, 250-y2, "Apple amount", 2);
	EcrireTexte(250-x3, 300-y2, "Snake size", 2);

	ChoisirEcran(4);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(250-x4, 150-y2, "Select field size", 2);
	EcrireTexte(250-x5, 250-y1, "20 x 30   40 x 60   60 x 90   80 x 120", 1);

	ChoisirEcran(5);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(250-x6, 150-y2, "Select Apple amount", 2);
	EcrireTexte(250-x7, 250-y1, "3   5   8   10", 1);

	EcrireTexte(6);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(250-x8, 150-y2, "Select Snake size", 2);
	EcrireTexte(250-x9, 250-y1, "5   7   10   15   20", 1);

	// if (_X >= 250-x3 && _X <= 250 + x3 && _Y >= 200-y && _Y <= 200 + y) {

	// 	CopierZone(3, 0, 0, 0, 500, 500, 0, 0);
	// 	int t = Touche();
	// 	while (t != '\n') {

	// 		t = Touche();
	// 	}

  
	// }

}