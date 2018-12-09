# TP 19 Exercice 1 : fichier Makefile

# CHAPITRE 1 : BUT FINAL

but : exo1

# CHAPITRE 2 : VARIABLES

OFILES = lire.o \
         personne.o \
         repertoire.o \
         options.o \
         main.o

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

personne.o : personne.h lire.h

repertoire.o : repertoire.h personne.h

options.o : options.h

main.o : personne.h repertoire.h options.h

#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES

lire.o : lire.s lire.h
	as -o lire.o lire.s

exo1 : $(OFILES)
	$(CC) $(CFLAGS) -o exo1 $(OFILES)

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) exo1

#CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean
