

int fct1(S_parameter* parameter) {

	int ysup = TailleSupPolice(2);
  	int yinf = TailleInfPolice(2);
  	int y = (ysup+yinf);
  	int x1 = TailleChaineEcran("SNAKE", 2);
  	int x2 = TailleChaineEcran("double click or touch to continue", 1);

	ChoisirEcran(1);
 	EffacerEcran(CouleurParNom("black"));
 	EcrireTexte(250-x1/2, 250-y/2, "SNAKE", 2);
 	EcrireTexte(250-x2/2, 280-y/2, "double click or touch to continue", 1);

 	ChoisirEcran(0);

 	while (!ToucheEnAttente() && !SourisCliquee()){}

 	CopierZone(1, 0, 0, 0, 500, 500, 0, 0);

 	fct2(&parameter);

 	return 0;
}

int fct2(S_parameter* parameter) {
	
	int y1up = TailleSupPolice(1);
  	int y1inf = TailleInfPolice(1);
  	int y1 = (ysup+yinf);
  	int y2sup = TailleSupPolice(2);
  	int y2inf = TailleInfPolice(2);
  	int y2 = (ysup+yinf);
	int x1 = TailleChaineEcran("START", 2);
  	int x2 = TailleChaineEcran("SETTINGS", 1);
  	int x3 = TailleChaineEcran("QUIT", 1);

  	ChoisirEcran(1);
  	EffacerEcran(CouleurParNom("black"));
  	EcrireTexte(3, 10, "Menu", 0);
 	EcrireTexte(250-x1/2, 200-y2/2, "START", 2);
 	EcrireTexte(250-x2/2, 250-y1/2, "SETTINGS", 1);
 	EcrireTexte(250-x3/2, 300-y1/2, "QUIT", 1);

 	ChoisirEcran(2);
  	EffacerEcran(CouleurParNom("black"));
  	EcrireTexte(3, 10, "Menu", 0);
 	EcrireTexte(250-x1/2, 200-y1/2, "START", 1);
 	EcrireTexte(250-x2/2, 250-y2/2, "SETTINGS", 2);
 	EcrireTexte(250-x3/2, 300-y1/2, "QUIT", 1);

	ChoisirEcran(3);
  	EffacerEcran(CouleurParNom("black"));
  	EcrireTexte(3, 10, "Menu", 0);
 	EcrireTexte(250-x1/2, 200-y1/2, "START", 1);
 	EcrireTexte(250-x2/2, 250-y1/2, "SETTINGS", 1);
 	EcrireTexte(250-x3/2, 300-y2/2, "QUIT", 2); 

 	ChoisirEcran(0);

 	CopierZone(1, 0, 0, 0, 500, 500, 0, 0);

  	int cursor = 0;

  	while (True) {

  		if (ToucheEnAttente()) {

  			T = Touche();
  			if (T == XK_Up && cursor != 0)
  				cursor -= 1;
  			if (T == XK_Down && cursor != 2)
  				cursor += 1;
  			if (T == XK_Return || T == XK_Right) {
  				if (cursor == 0) {
  					fct3_1(parameter);
  					return 0;
  				}
  				else if (cursor == 1) {
  					fct3_2(parameter);
  					return 0;
  				}
  				else {
  					fct3_3(parameter);
  					return 0;
  				}
  			}
  			if (T == XK_Left) {
  				fct1(parameter);
  				return 0;
  			}


  			if (cursor == 0)
  				CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
  			else if (cursor == 1)
  				CopierZone(2, 0, 0, 0, 500, 500, 0, 0);
  			else 
  				CopierZone(3, 0, 0, 0, 500, 500, 0, 0);
  		}
  	}
}

int fct3_1(S_parameter* parameter) {
	Start(parameter);
}

int fct3_2(S_parameter* parameter) {

}

int fct3_3(S_parameter* parameter) {
	FermerGraphique();
	return 0;
}