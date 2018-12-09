OFILES = main.o meno.o settings.o

GCCFLAGS = -Wall -ansi -pedantic -g

exe : $(OFILES)
	gcc $(GCCFLAGS) -o exe $(OFILES)

menu.o : menu.c menu.h
	gcc -c menu.c

settings.o : settings.c settings.h
	gcc -c settings.c

clean :
	-rm -f $(OFILES) exe