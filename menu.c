#include "menu.h"
#include "settings.h"
#include "start.h"
#include <graph.h>

int Menu() {

  int gridWidth = 60;
  int gridHeigth = 40;
  int appleAmount = 5;
  int snakeSize = 10;

  int ysup = TailleSupPolice(2);
  int yinf = TailleInfPolice(2);
  int y = (ysup+yinf);
  int x1 = TailleChaineEcran("SNAKE", 2);
  int x2 = TailleChaineEcran("double click or touch to continue", 1);
  int x3 = TailleChaineEcran("START", 2);
  int x4 = TailleChaineEcran("SETTINGS", 2);
  int x5 = TailleChaineEcran("QUIT", 2);

  ChoisirEcran(1);
  EffacerEcran(CouleurParNom("black"));
 	EcrireTexte(250-x1/2, 250-y/2, "SNAKE", 2);
 	EcrireTexte(250-x2/2, 280-y/2, "double click or touch to continue", 1);

 	ChoisirEcran(2);
  EffacerEcran(CouleurParNom("black"));
  EcrireTexte(3, 10, "Menu", 0);
 	EcrireTexte(250-x3/2, 200-y/2, "START", 2);
 	EcrireTexte(250-x4/2, 250-y/2, "SETTINGS", 2);
 	EcrireTexte(250-x5/2, 300-y/2, "QUIT", 2);

 	ChoisirEcran(0);

  CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
  
  while (!ToucheEnAttente() && !SourisCliquee()){}

  CopierZone(2, 0, 0, 0, 500, 500, 0, 0);

  while(!SourisCliquee()) {}

  while (1) {

    SourisCliquee();

    if (_X >= 250-x5 && _X <= 250+x5 && _Y >= 300-y && _Y <= 300+y) {
        
      FermerGraphique();
      exit(0);
    
    }

    SourisCliquee();

    if (_X >= 250-x4 && _X <= 250+x4 && _Y >= 250-y && _Y <= 250+y) {

      Settings(&gridWidth, &gridHeigth, &appleAmount, &snakeSize);

    }

    SourisCliquee();

    if (_X >= 250-x3 && _X <= 250+x3 && _Y >= 200-y && _Y <= 200+y) {

      Start(gridWidth, gridHeigth, appleAmount, snakeSize);

    }

  }

  while (1) {}

    exit(0);

}