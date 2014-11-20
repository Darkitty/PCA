#include "Pile.h"

int main(int argc, char const *argv[])
{
	pile_t* pile;

	printf("%d\n", empty(pile));

	stack(pile, 2);
	printf("%d\n", empty(pile));	

	return 0;
}