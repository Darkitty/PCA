#include "Pile.h"

int main()
{
	pile_t pile;
	pile_t* ptr_pile = &pile;
	double variable;

	int i = initPile(ptr_pile, 10);
	printf("\n%s\n", "----------------------------------------");
	printf("%s\n", "------------ TEST NORMAUX --------------");
	printf("%s\n", "----------------------------------------");
	printf("%s\n", "----- TEST PILE INIT -----");
	printf("Résultat attendu -> 0 : %d\n", i);

	printf("%s\n", "----- TEST PILE VIDE -----");
	printf("Résultat attendu -> 1 : %d\n", empty(ptr_pile));

	printf("%s\n", "----- TEST STACK -----");
	stack(ptr_pile, 2);
	printf("Résultat attendu -> 0 : %d\n", empty(ptr_pile));

	printf("%s\n", "----- TEST UNSTACK -----");
	variable = unstack(ptr_pile);
	printf("Résultat attendu -> 2 : %f\n", variable);
	printf("Résultat attendu -> 1 : %d\n", empty(ptr_pile));	

	printf("%s\n", "----- TEST FREESPACE -----");
	printf("Résultat attendu -> 10 : %d\n", freeSpace(ptr_pile));

	printf("%s\n", "----- TEST OCCUPEDSPACE -----");
	printf("Résultat attendu -> 0 : %d\n", occupedSpace(ptr_pile));

	printf("\n%s\n", "----------------------------------------");
	printf("%s\n", "--------- TEST CAS CRITIQUES -----------");
	printf("%s\n", "----------------------------------------");
	printf("%s\n", "----- TEST UNSTACK PILE VIDE -----");
	initPile(ptr_pile, 2);
	printf("Résultat attendu -> -1 : %f\n", unstack(ptr_pile));


	printf("%s\n", "----- TEST STACK PILE PLEINE -----");
	stack(ptr_pile, 2);
	stack(ptr_pile, 2);	
	printf("Résultat attendu -> -1 : %i\n", stack(ptr_pile, 2));

	return 0;
}