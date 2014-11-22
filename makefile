CC = gcc
SRC = Pile.c List.c Main.c
OBJ = $(SRC: .c=.o)
CFLAGS=-W -Wall -ansi -pedantic -lm -g -o2 -pipe

exec: $(OBJ)
	gcc -o exec $(OBJ)
fonc.o : fonc.c
	$(CC) -o $@ -c $< $(CFLAGS)
Main.o : Main.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o exec*