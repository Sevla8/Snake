
OFILES = main.o \
		 menu.o \
		 settings.o \
		 start.o \
		 print.o

HFILES = menu.h \
		 settings.h \
		 defines.h \
		 coord.h \
		 square.h \
		 grid.h \
		 snake.h \
		 player.h \
		 start.h \
		 print.h

CFILES = main.c \
         menu.c \
         settings.c \
         start.c \
         print.c

GCCFLAGS = -Wall -ansi -pedantic -g

GRAPH = -lgraph -I/usr/local/include -L/usr/local/lib

exe : $(OFILES)
	gcc $(GCCFLAGS) -o exe $(OFILES) $(GRAPH)

main.o : main.c $(HFILES)
	gcc -c main.c

menu.o : menu.c menu.h settings.h
	gcc -c menu.c

settings.o : settings.c settings.h
	gcc -c settings.c

start.o : start.c start.h
	gcc -c start.c

print.o : print.c print.h
	gcc -c print.c
clean :
	-rm -f $(OFILES) exe

.PHONY : clean
