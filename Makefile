OFILES = main.o \
		 menu.o \
		 start.o \
		 game.o

HFILES = menu.h \
		 defines.h \
		 coord.h \
		 case.h \
		 parameter.h \
		 snake.h \
		 player.h \
		 start.h \
		 game.h \
		 node.h

CFILES = main.c \
         menu.c \
         start.c \
         game.c

GCCFLAGS = -Wall -ansi -pedantic -g

GRAPH = -lgraph -I/usr/local/include -L/usr/local/lib

a.out : $(OFILES)
	gcc $(GCCFLAGS) -o a.out $(OFILES) $(GRAPH)

main.o : main.c parameter.h menu.h start.h
	gcc -c main.c

menu.o : menu.c menu.h start.h
	gcc -c menu.c
	
start.o : start.c start.h case.h coord.h snake.h direction.h node.h
	gcc -c start.c

game.o : game.c game.h case.h snake.h defines.h
	gcc -c game.c

clean :
	-rm -f $(OFILES) a.out

.PHONY : clean