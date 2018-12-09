#include <stdlib.h>
#include <graph.h>

int main(int argc, char* argv[]) {

  InitialiserGraphique();
  CreerFenetre(50,50,500,500);
  EffacerEcran(CouleurParNom("black"));
  ChoisirCouleurDessin(CouleurParNom("white"));

  unsigned long time0 = Microsecondes();
  unsigned long seconde = 1000000;

  int ysup = TailleSupPolice(2);
  int yinf = TailleInfPolice(2);
  int y = (ysup+yinf)/2;
  int x1 = TailleChaineEcran("SNAKE", 2)/2;
  int x2 = TailleChaineEcran("double click or touch to continue", 1)/2;
  int x3 = TailleChaineEcran("START", 2)/2;
  int x4 = TailleChaineEcran("SETTINGS", 2)/2;
  int x5 = TailleChaineEcran("QUIT", 2)/2;

  ChoisirEcran(1);
  EffacerEcran(CouleurParNom("black"));
 	EcrireTexte(250-x1, 250-y, "SNAKE", 2);
 	EcrireTexte(250-x2, 280-y, "double click or touch to continue", 1);

 	ChoisirEcran(2);
  EffacerEcran(CouleurParNom("black"));
 	EcrireTexte(250-x3, 200-y, "START", 2);
 	EcrireTexte(250-x4, 250-y, "SETTINGS", 2);
 	EcrireTexte(250-x5, 300-y, "QUIT", 2);

  ChoisirEcran(3);
  EffacerEcran(CouleurParNom("black"));
  ///////a finir////////

 	ChoisirEcran(0);

  CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
  
  while (!ToucheEnAttente() && !SourisCliquee()){}

  CopierZone(2, 0, 0, 0, 500, 500, 0, 0);

  while (!SourisCliquee()) {}

  SourisCliquee();

  if (_X >= 250-x5 && _X <= 250+x5 && _Y >= 300-y && _Y <= 300+y) {
      
    FermerGraphique();
  
  }

  if (_X >= 250-x4 && _X <= 250+x4 && _Y >= 250-y && _Y <= 250+y) {

    Settings();

  }

  if (_X >= 250-x3 && _X <= 250+x3 && _Y >= 200-y && _Y <= 200+y) {

    Start();

  }

  while (1) {}
  
  exit(0);
}



