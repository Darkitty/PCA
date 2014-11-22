#include "Pile.h"

int main()
{
	pile_t pile;
	pile_t* ptr_pile = &pile;
	double variable;

	int i = initPile(ptr_pile, 10);
	printf("%s\n", "----- TEST PILE INIT -----");
	printf("%d\n", i);

	printf("%s\n", "----- TEST PILE VIDE -----");
	printf("%d\n", empty(ptr_pile));

	printf("%s\n", "----- TEST STACK -----");
	stack(ptr_pile, 2);
	printf("%d\n", empty(ptr_pile));

	printf("%s\n", "----- TEST UNSTACK -----");
	variable = unstack(ptr_pile);
	printf("%f\n", variable);
	printf("%d\n", empty(ptr_pile));	

	printf("%s\n", "----- TEST FREESPACE -----");
	printf("%d\n", freeSpace(ptr_pile));

	printf("%s\n", "----- TEST OCCUPEDSPACE -----");
	printf("%d\n", occupedSpace(ptr_pile));

	return 0;
}