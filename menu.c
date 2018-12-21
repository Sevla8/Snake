#include "menu.h"

char* inttostr(int nb){
	if (nb == 0){
		char* tab = (char*) malloc(sizeof(char) * 2);
		tab[0] = '0'; tab[1] = '\0';
		return tab;
	}
	int cp = nb;
	int l = 0;
	while (cp != 0){
		cp = cp / 10;
		l = l+1;
	}
	cp = nb;
	char* tab = (char*) malloc(sizeof(char) * (l + 1));
	for (int i = 0; i < l; i = i+1){
		tab[l-1-i] = cp % 10 + 48;
		cp = cp / 10;
	}
	tab[l] = '\0';
	return tab;
}

int screen_1(S_parameter* parameter) {

  	int y2sup = TailleSupPolice(2);
	int y2inf = TailleInfPolice(2);
	int y2 = (y2sup+y2inf);
	int y1sup = TailleSupPolice(1);
	int y1inf = TailleInfPolice(1);
	int y1 = (y1sup+y1inf);
	int x1 = TailleChaineEcran("SNAKE", 2);
	int x2 = TailleChaineEcran("click or press a key to continue", 1);

	ChoisirEcran(1);
 	EffacerEcran(CouleurParNom("black"));
  	ChoisirCouleurDessin(CouleurParNom("white"));
 	EcrireTexte(250-x1/2, 250-y2/2, "SNAKE", 2);
 	EcrireTexte(250-x2/2, 280-y1/2, "click or press a key to continue", 1);

  	CopierZone(1, 0, 0, 0, 500, 500, 0, 0);

 	while (!ToucheEnAttente() && !SourisCliquee()){}

  	if (ToucheEnAttente())
    	Touche();

 	screen_help(parameter);

 	return screen_2(parameter);
}

void screen_help() {

	int y2sup = TailleSupPolice(2);
	int y2inf = TailleInfPolice(2);
	int y2 = (y2sup+y2inf);
	int y1sup = TailleSupPolice(1);
	int y1inf = TailleInfPolice(1);
	int y1 = (y1sup+y1inf);
	int y0sup = TailleSupPolice(0);
	int y0inf = TailleInfPolice(0);
	int y0 = (y0sup+y0inf);
	int x1 = TailleChaineEcran("COMMANDS", 2);
	int x2 = TailleChaineEcran("press h to display this page again", 0);

	ChoisirEcran(7);
 	EffacerEcran(CouleurParNom("black"));
 	EcrireTexte(250-x1/2, 50-y2/2, "COMMANDS", 2);
 	EcrireTexte(50, 100-y1/2, "In Menu :", 1);
 	EcrireTexte(150, 100-y0/2, "confirm : RIGHTARROW", 0);
 	EcrireTexte(150, 125-y0/2, "cancel : LEFTARROW", 0);
 	EcrireTexte(150, 150-y0/2, "increase : UPARROW", 0);
 	EcrireTexte(150, 175-y0/2, "decrease : DOWNARROW", 0);
 	EcrireTexte(150, 200-y0/2, "decrease : DOWNARROW", 0);
 	EcrireTexte(50, 300-y1/2, "In Game :", 1);
 	EcrireTexte(150, 325-y0/2, "move snake rightward : RIGHTARROW", 0);
 	EcrireTexte(150, 350-y0/2, "move snake leftward : LEFTARROW", 0);
 	EcrireTexte(150, 375-y0/2, "move snake upward : UPARROW", 0);
 	EcrireTexte(150, 400-y0/2, "move snake downward : DOWNARROW", 0);
 	EcrireTexte(50, 450-y1/2, "You can also use the mouse", 1);
 	EcrireTexte(490-x2, 475-y0/2, "press h to display this page again", 0);

 	CopierZone(7, 0, 0, 0, 500, 500, 0, 0);

 	unsigned long time = Microsecondes();

 	while(!(Microsecondes() > time + 10*SECONDE || ToucheEnAttente() || SourisCliquee())){}
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
	int souris = 0;

	while (True) {

		SourisPosition();
		if (_X >= 250-x11 && _X <= 250+x11 && _Y >= 200-y1*2 && _Y <= 200) {
			CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			if (SourisCliquee() && _X >= 250-x11 && _X <= 250+x11 && _Y >= 200-y1*2 && _Y <= 200) 
				return Start(parameter);
		}

		SourisPosition();
		if (_X >= 250-x21 && _X <= 250+x21 && _Y >= 250-y1*2 && _Y <= 250) {
			CopierZone(2, 0, 0, 0, 500, 500, 0, 0);
			if (SourisCliquee() && _X >= 250-x21 && _X <= 250+x21 && _Y >= 250-y1*2 && _Y <= 250)
				return screen_3(parameter);
		}

		SourisPosition();
		if (_X >= 250-x31 && _X <= 250+x31 && _Y >= 300-y1*2 && _Y <= 300) {
			CopierZone(3, 0, 0, 0, 500, 500, 0, 0);
			if (SourisCliquee() && _X >= 250-x31 && _X <= 250+x31 && _Y >= 300-y1*2 && _Y <= 300)
				return -1;
		}


		if (ToucheEnAttente()) {

			int T = Touche();
			if (T == 'h') {
				screen_help();
				CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			}
			if (T == XK_Up && cursor != 0)
				cursor -= 1;
			if (T == XK_Down && cursor != 2)
				cursor += 1;
			if (T == XK_Right) {
				if (cursor == 0) 
					return 1;
				if (cursor == 1) 
					return screen_3(parameter);
				if (cursor == 2) 
					return -1;
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

int screen_3(S_parameter* parameter) {

	int y2sup = TailleSupPolice(2);
    int y2inf = TailleInfPolice(2);
    int y2 = (y2sup+y2inf)/2;
    int y1sup = TailleSupPolice(1);
    int y1inf = TailleInfPolice(1);
    int y1 = (y1sup+y1inf)/2;
    int x11 = TailleChaineEcran("Field Size", 1);
  	int x21 = TailleChaineEcran("Apple amount", 1);
  	int x31 = TailleChaineEcran("Snake size", 1);
	int x12 = TailleChaineEcran("Field Size", 2);
  	int x22 = TailleChaineEcran("Apple amount", 2);
  	int x32 = TailleChaineEcran("Snake size", 2);

  	ChoisirEcran(1);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu > Settings", 0);
	EcrireTexte(250-x12/2, 200-y2/2, "Field Size", 2);
	EcrireTexte(250-x21/2, 250-y1/2, "Apple amount", 1);
	EcrireTexte(250-x31/2, 300-y1/2, "Snake size", 1);

	ChoisirEcran(2);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu > Settings", 0);
	EcrireTexte(250-x11/2, 200-y1/2, "Field Size", 1);
	EcrireTexte(250-x22/2, 250-y2/2, "Apple amount", 2);
	EcrireTexte(250-x31/2, 300-y1/2, "Snake size", 1);

	ChoisirEcran(3);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu > Settings", 0);
	EcrireTexte(250-x11/2, 200-y1/2, "Field Size", 1);
	EcrireTexte(250-x21/2, 250-y1/2, "Apple amount", 1);
	EcrireTexte(250-x32/2, 300-y2/2, "Snake size", 2);

	CopierZone(1, 0, 0, 0, 500, 500, 0, 0);

	int cursor = 0;

	while (True) {

		SourisPosition();
		if (_X >= 250-x11 && _X <= 250+x11 && _Y >= 200-y1*2 && _Y <= 200) {
			CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			if (SourisCliquee() && _X >= 250-x11 && _X <= 250+x11 && _Y >= 200-y1*2 && _Y <= 200) 
				return screen_4_1(parameter);
		}

		SourisPosition();
		if (_X >= 250-x21 && _X <= 250+x21 && _Y >= 250-y1*2 && _Y <= 250) {
			CopierZone(2, 0, 0, 0, 500, 500, 0, 0);
			if (SourisCliquee() && _X >= 250-x21 && _X <= 250+x21 && _Y >= 250-y1*2 && _Y <= 250)
				return screen_4_2(parameter);
		}

		SourisPosition();
		if (_X >= 250-x31 && _X <= 250+x31 && _Y >= 300-y1*2 && _Y <= 300) {
			CopierZone(3, 0, 0, 0, 500, 500, 0, 0);
			if (SourisCliquee() && _X >= 250-x31 && _X <= 250+x31 && _Y >= 300-y1*2 && _Y <= 300)
				return screen_4_3(parameter);
		}

		if (ToucheEnAttente()) {

			int T = Touche();
			if (T == 'h') {
				screen_help();
				CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			}
			if (T == XK_Up && cursor != 0)
				cursor -= 1;
			if (T == XK_Down && cursor != 2)
				cursor += 1;
			if (T == XK_Right) {
				if (cursor == 0) 
					return screen_4_1(parameter);
				if (cursor == 1) 
					return screen_4_2(parameter);
				if (cursor == 2) 
					return screen_4_3(parameter);
			}
			if (T == XK_Left)
				return screen_2(parameter);

			if (cursor == 0)
				CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			else if (cursor == 1)
				CopierZone(2, 0, 0, 0, 500, 500, 0, 0);
			else 
				CopierZone(3, 0, 0, 0, 500, 500, 0, 0);
		}
	}
}

int screen_4_1(S_parameter* parameter) {

	int y2sup = TailleSupPolice(2);
    int y2inf = TailleInfPolice(2);
    int y2 = (y2sup+y2inf)/2;
    int y1sup = TailleSupPolice(1);
    int y1inf = TailleInfPolice(1);
    int y1 = (y1sup+y1inf)/2;
    int y0sup = TailleSupPolice(0);
    int y0inf = TailleInfPolice(0);
    int y0 = (y0sup+y0inf)/2;

    int x = TailleChaineEcran("Select field size", 2);
    int x10 = TailleChaineEcran("40 x 60", 0);
  	int x20 = TailleChaineEcran("60 x 100", 0);
  	int x30 = TailleChaineEcran("80 x 120", 0);
	int x11 = TailleChaineEcran("40 x 60", 1);
  	int x21 = TailleChaineEcran("60 x 100", 1);
  	int x31 = TailleChaineEcran("80 x 120", 1);

  	ChoisirEcran(1);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu > Settings > Field Size", 0);
	EcrireTexte(250-x/2, 150-y2/2, "Select field size",2);
	EcrireTexte(250-x11/2, 200-y1/2, "40 x 60", 1);
	EcrireTexte(250-x20/2, 250-y0/2, "60 x 100", 0);
	EcrireTexte(250-x30/2, 300-y0/2, "80 x 120", 0);

  	ChoisirEcran(2);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu > Settings > Field Size", 0);
	EcrireTexte(250-x/2, 150-y2/2, "Select field size",2);
	EcrireTexte(250-x10/2, 200-y0/2, "40 x 60", 0);
	EcrireTexte(250-x21/2, 250-y1/2, "60 x 100", 1);
	EcrireTexte(250-x30/2, 300-y0/2, "80 x 120", 0);

	ChoisirEcran(3);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu > Settings > Field Size", 0);
	EcrireTexte(250-x/2, 150-y2/2, "Select field size",2);
	EcrireTexte(250-x10/2, 200-y0/2, "40 x 60", 0);
	EcrireTexte(250-x20/2, 250-y0/2, "60 x 100", 0);
	EcrireTexte(250-x31/2, 300-y1/2, "80 x 120", 1);

	CopierZone(1, 0, 0, 0, 500, 500, 0, 0);

	int cursor = 0;

	while (True) {

		SourisPosition();
		if (_X >= 250-x10 && _X <= 250+x10 && _Y >= 200-y0*2 && _Y <= 200) {
			CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			if (SourisCliquee() && _X >= 250-x10 && _X <= 250+x10 && _Y >= 200-y0*2 && _Y <= 200) {
				parameter->gridWidth = 60;
				parameter->gridLength = 40;
				return screen_3(parameter);
			}
		}

		SourisPosition();
		if (_X >= 250-x21 && _X <= 250+x21 && _Y >= 250-y1*2 && _Y <= 250) {
			CopierZone(2, 0, 0, 0, 500, 500, 0, 0);
			if (SourisCliquee() && _X >= 250-x20 && _X <= 250+x21 && _Y >= 250-y1*2 && _Y <= 250) {
				parameter->gridWidth = 100;
				parameter->gridLength = 60;
				return screen_3(parameter);
			}
		}

		SourisPosition();
		if (_X >= 250-x31 && _X <= 250+x31 && _Y >= 300-y1*2 && _Y <= 300) {
			CopierZone(3, 0, 0, 0, 500, 500, 0, 0);
			if (SourisCliquee() && _X >= 250-x31 && _X <= 250+x31 && _Y >= 300-y1*2 && _Y <= 300) {
				parameter->gridWidth = 120;
				parameter->gridLength = 80;
				return screen_3(parameter);
			}
		}

		if (ToucheEnAttente()) {

			int T = Touche();
			if (T == 'h') {
				screen_help();
				CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			}
			if (T == XK_Up && cursor != 0)
				cursor -= 1;
			if (T == XK_Down && cursor != 2)
				cursor += 1;
			if (T == XK_Right) {
				if (cursor == 0) {
					parameter->gridWidth = 60;
					parameter->gridLength = 40;
					return screen_3(parameter);
				}
				if (cursor == 1) {
					parameter->gridWidth = 100;
					parameter->gridLength = 60;
					return screen_3(parameter);
				}
				if (cursor == 2) {
					parameter->gridWidth = 120;
					parameter->gridLength = 80;
					return screen_3(parameter);
				}
			}
			if (T == XK_Left)
				return screen_2(parameter);

			if (cursor == 0)
				CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			else if (cursor == 1)
				CopierZone(2, 0, 0, 0, 500, 500, 0, 0);
			else 
				CopierZone(3, 0, 0, 0, 500, 500, 0, 0);
		}
	}
}

int screen_4_2(S_parameter* parameter) {

	int y2sup = TailleSupPolice(2);
    int y2inf = TailleInfPolice(2);
    int y2 = (y2sup+y2inf)/2;
    int y1sup = TailleSupPolice(1);
    int y1inf = TailleInfPolice(1);
    int y1 = (y1sup+y1inf)/2;

    int x = TailleChaineEcran("Select apple amount", 2);

  	ChoisirEcran(1);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu > Settings > Apple Amount", 0);
	EcrireTexte(250-x/2, 150-y2/2, "Select apple amount",2);
	EcrireTexte(250, 200-y1/2, "5", 1);

	CopierZone(1, 0, 0, 0, 500, 500, 0, 0);

	int cursor = 5;

	while (True) {

		if (ToucheEnAttente()) {

			int T = Touche();
			if (T == 'h') {
				screen_help();
				CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			}
			if (T == XK_Up && cursor != 10)
				cursor += 1;
			if (T == XK_Down && cursor != 1)
				cursor -= 1;
			if (T == XK_Right) {
				parameter->appleAmount = cursor;
				return screen_3(parameter);
			}
			if (T == XK_Left)
				return screen_3(parameter);

			ChoisirEcran(1);
			EffacerEcran(CouleurParNom("black"));
			EcrireTexte(3, 10, "Menu > Settings > Apple Amount", 0);
			EcrireTexte(250-x/2, 150-y2/2, "Select apple amount",2);
			EcrireTexte(250, 200-y1/2, inttostr(cursor), 1);

			CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
		}
	}
}
  
int screen_4_3(S_parameter* parameter) {

	int y2sup = TailleSupPolice(2);
    int y2inf = TailleInfPolice(2);
    int y2 = (y2sup+y2inf)/2;
    int y1sup = TailleSupPolice(1);
    int y1inf = TailleInfPolice(1);
    int y1 = (y1sup+y1inf)/2;

    int x = TailleChaineEcran("Select snike size", 2);

  	ChoisirEcran(1);
	EffacerEcran(CouleurParNom("black"));
	EcrireTexte(3, 10, "Menu > Settings > Snake Size", 0);
	EcrireTexte(250-x/2, 150-y2/2, "Select snake size",2);
	EcrireTexte(250, 200-y1/2, "10", 1);

	CopierZone(1, 0, 0, 0, 500, 500, 0, 0);

	int cursor = 10;

	while (True) {

		if (ToucheEnAttente()) {

			int T = Touche();
			if (T == 'h') {
				screen_help();
				CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
			}
			if (T == XK_Up && cursor != 20)
				cursor += 1;
			if (T == XK_Down && cursor != 1)
				cursor -= 1;
			if (T == XK_Right) {
				parameter->snakeSize = cursor;
				return screen_3(parameter);
			}
			if (T == XK_Left)
				return screen_3(parameter);

			ChoisirEcran(1);
			EffacerEcran(CouleurParNom("black"));
			EcrireTexte(3, 10, "Menu > Settings > Snake Size", 0);
			EcrireTexte(250-x/2, 150-y2/2, "Select snake size",2);
			EcrireTexte(250, 200-y1/2, inttostr(cursor), 1);

			CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
		}
	}
}