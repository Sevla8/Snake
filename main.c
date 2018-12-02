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
    int x2 = TailleChaineEcran("click or touch to continue", 2)/2;

    ChoisirEcran(1);
    EffacerEcran(CouleurParNom("black"));
   	EcrireTexte(250-x1, 250-y, "SNAKE", 2);
   	EcrireTexte(250-x2, 280-y, "click or touch to continue", 2);

   	ChoisirEcran(0);
    
    while (ToucheEnAttente() == 0 && SourisCliquee() == 0){

    	if (Microsecondes() >= time0 + 0.5*seconde) {
    		CopierZone(1, 0, 0, 0, 500, 500, 0, 0);
    		while (Microsecondes() < time0 + 3*seconde) {}
    		EffacerEcran(CouleurParNom("black"));
    		time0 = Microsecondes();
    	}
	}
}
