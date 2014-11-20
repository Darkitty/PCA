#include "Pile.h"

int main(int argc, char const *argv[])
{
	pile_t* pile;

	initPile(pile, 10);

	printf("%s\n", "----- TEST PILE VIDE -----");
	printf("%d\n", empty(pile));

	printf("%s\n", "----- TEST STACK -----");
	stack(pile, 2);
	printf("%d\n", empty(pile));

	printf("%s\n", "----- TEST UNSTACK -----");
	double variable;
	variable = unstack(pile);
	printf("%f\n", variable);
	printf("%d\n", empty(pile));	

	printf("%s\n", "----- TEST FREESPACE -----");
	printf("%d\n", freeSpace(pile));

	printf("%s\n", "----- TEST OCCUPEDSPACE -----");
	printf("%d\n", occupedSpace(pile));

	return 0;
}