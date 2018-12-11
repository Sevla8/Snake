#include <stdlib.h>
#include <graph.h>

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

	int longueur = 40;
	int largeur = 60;

	int taillePixel = 5;

	int longueurEcran = longueur * taillePixel;
	int largeurEcran = largeur * taillePixel;

	InitialiserGraphique();
	CreerFenetre(50, 50, longueurEcran, largeurEcran);

}