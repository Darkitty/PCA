#include "Pile.h"
#include "List.h"

int main(int argc, char const *argv[])
{
	pile_t pile;
	pile_t* ptr_pile = &pile;

	initPile(ptr_pile, 10);

	printf("%s\n", "----- TEST PILE VIDE -----");
	printf("%d\n", empty(ptr_pile));

	printf("%s\n", "----- TEST STACK -----");
	stack(ptr_pile, 2);
	printf("%d\n", empty(ptr_pile));

	printf("%s\n", "----- TEST UNSTACK -----");
	double variable;
	variable = unstack(ptr_pile);
	printf("%f\n", variable);
	printf("%d\n", empty(ptr_pile));	

	printf("%s\n", "----- TEST FREESPACE -----");
	printf("%d\n", freeSpace(ptr_pile));

	printf("%s\n", "----- TEST OCCUPEDSPACE -----");
	printf("%d\n", occupedSpace(ptr_pile));

	return 0;
}