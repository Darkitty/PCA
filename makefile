# Parameters for compilation
CC = gcc
SRC_PILE = Pile.c test_Pile.c
OBJ = $(SRC: .c=.o)
CFLAGS=-W -Wall -ansi -pedantic -lm -g -o2 -pipe

# Main make for final executable
exec: $(OBJ)
	$(CC) -o exec $(OBJ)


# Compilation for Pile and its tests
test_Pile: test_Pile.o
	$(CC) -o test_Pile $(SRC_PILE) $(CFLAGS)
test_Pile.o: test_Pile.c Pile.h
	$(CC) -o test_Pile.o -c test_Pile.c $(CFLAGS)
Pile.o: Pile.c Pile.h
	$(CC) -o Pile.o -c Pile.c $(CFLAGS)

# Utilities
clean:
	rm -f *.o exec*