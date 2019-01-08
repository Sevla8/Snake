OFILES = main.o \
         menu.o \
         start.o \
         tools.o \
         game.o

FLAGS = -Wall -ansi -pedantic -g

GRAPH = -lgraph -I/usr/local/include -L/usr/local/lib

exe : $(OFILES)
	gcc $(FLAGS) -o exe $(OFILES) $(GRAPH)

main.o : main.c
	gcc -c main.c

menu.o : menu.c menu.h
	gcc -c menu.c

start.o : start.c start.h
	gcc -c start.c

tools.o : tools.c tools.h
	gcc -c tools.c

game.o : game.c game.h
	gcc -c game.c

	touch level.txt; echo -n "1" > level.txt; touch score.txt; echo -n "0" > score.txt; 

.PHONY : clean

clean :
	rm -f $(OFILES) exe level.txt score.txt