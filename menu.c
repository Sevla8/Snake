#include "menu.h"

int screen_1(S_parameter* parameter) {

  int ysup = TailleSupPolice(2);
	int yinf = TailleInfPolice(2);
	int y = (ysup+yinf);
	int x1 = TailleChaineEcran("SNAKE", 2);
	int x2 = TailleChaineEcran("double click or touch to continue", 1);

	ChoisirEcran(1);
 	EffacerEcran(CouleurParNom("black"));
  ChoisirCouleurDessin(CouleurParNom("white"));
 	EcrireTexte(250-x1/2, 250-y/2, "SNAKE", 2);
 	EcrireTexte(250-x2/2, 280-y/2, "double click or touch to continue", 1);

  CopierZone(1, 0, 0, 0, 500, 500, 0, 0);

 	while (!ToucheEnAttente() && !SourisCliquee()){}

  if (ToucheEnAttente())
    Touche();

 	return screen_2(parameter);
}

int screen_2(S_parameter* parameter) {
	
	int y1sup = TailleSupPolice(1);
	int y1inf = TailleInfPolice(1);
	int y1 = (y1sup+y1inf);
	int y2sup = TailleSupPolice(2);
	int y2inf = TailleInfPolice(2);
	int y2 = (y2sup+y2inf);
	int x12 = TailleChaineEcran("START", 2);
	int x22 = TailleChaineEcran("SETTINGS", 2);
	int x32 = TailleChaineEcran("QUIT", 2);
  int x11 = TailleChaineEcran("START", 1);
  int x21 = TailleChaineEcran("SETTINGS", 1);
  int x31 = TailleChaineEcran("QUIT", 1);

	ChoisirEcran(1);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu", 0);
 	EcrireTexte(250-x12/2, 200-y2/2, "START", 2);
 	EcrireTexte(250-x21/2, 250-y1/2, "SETTINGS", 1);
 	EcrireTexte(250-x31/2, 300-y1/2, "QUIT", 1);

 	ChoisirEcran(2);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu", 0);
 	EcrireTexte(250-x11/2, 200-y1/2, "START", 1);
 	EcrireTexte(250-x22/2, 250-y2/2, "SETTINGS", 2);
 	EcrireTexte(250-x31/2, 300-y1/2, "QUIT", 1);

	ChoisirEcran(3);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu", 0);
 	EcrireTexte(250-x11/2, 200-y1/2, "START", 1);
 	EcrireTexte(250-x21/2, 250-y1/2, "SETTINGS", 1);
 	EcrireTexte(250-x32/2, 300-y2/2, "QUIT", 2);

 	CopierZone(1, 0, 0, 0, 500, 500, 0, 0);

	int cursor = 0;

	while (True) {

		if (ToucheEnAttente()) {

			int T = Touche();
			if (T == XK_Up && cursor != 0)
				cursor -= 1;
			if (T == XK_Down && cursor != 2)
				cursor += 1;
			if (T == XK_Right) {
				if (cursor == 0) 
					return screen_3_1(parameter);
				if (cursor == 1) 
					return screen_3_2(parameter);
				if (cursor == 2) 
					return screen_3_3(parameter);
			}
			if (T == XK_Left)
				return screen_1(parameter);

			if (cursor == 0)
				CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			else if (cursor == 1)
				CopierZone(2, 0, 0, 0, 500, 500, 0, 0);
			else 
				CopierZone(3, 0, 0, 0, 500, 500, 0, 0);
		}
	}
}

int screen_3_1(S_parameter* parameter) {
	return 1;
}

int screen_3_2(S_parameter* parameter) {

}

int screen_3_3(S_parameter* parameter) {
	return -1;
}

int screen_4(S_parameter* parameter) {

  
}