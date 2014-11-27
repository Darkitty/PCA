# Parameters for compilation
CC = gcc
SRC = Pile.c List.c
OBJ = $(SRC: .c=.o)
CFLAGS=-W -Wall -ansi -pedantic -lm -g -O2 -pipe

# SRC variables for moduls
SRC_PILE = Pile.c test_Pile.c
SRC_LIST = List.c test_List.c
SRC_CELL = Cell.c test_Cell.c Pile.c List.c


# Main make for final executable
exec: $(OBJ)
	$(CC) -o exec $(OBJ)


# Compilation for Pile and its tests
test_Pile: test_Pile.c Pile.c Pile.h
	$(CC) -o test_Pile $(SRC_PILE) $(CFLAGS)
# Compilation for List and its tests
test_List: test_List.c List.c List.h
	$(CC) -o test_List $(SRC_LIST) $(CFLAGS)
# Compilation for Cell and its tests
test_Cell: test_Cell.c Cell.c Cell.h List.h Pile.h List.c
	$(CC) -o test_Cell $(SRC_CELL) $(CFLAGS)


# Utilities
clean:
	rm -f *.o exec* *.exe*

# Generic rules
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)