# Parameters for compilation
CC = gcc
SRC = Pile.c List.c
OBJ = $(SRC: .c=.o)
CFLAGS=-W -Wall -ansi -pedantic -lm -g -o2 -pipe

# SRC variables for moduls
SRC_PILE = Pile.c test_Pile.c
SRC_LIST = List.c test_List.c


# Main make for final executable
exec: $(OBJ)
	$(CC) -o exec $(OBJ)


# Compilation for Pile and its tests
test_Pile: test_Pile.o
	$(CC) -o test_Pile $(SRC_PILE) $(CFLAGS)

# Compilation for List and its tests
test_List: test_List.o
	$(CC) -o test_List $(SRC_PILE) $(CFLAGS)


# Utilities
clean:
	rm -f *.o exec* 2*

# Generic rules
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)