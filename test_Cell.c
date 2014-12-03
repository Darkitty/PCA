#include "Cell.h"

int main()
{
	cell_t cell;
	cell_t* ptr_cell = &cell;
	char* saisi = "= 3 4 5 + *";
	char* string = "pca pca";

	ptr_cell->saisi = saisi;
	ptr_cell->name = "A1";

	list_t* ptr_listCell;

	cell_t cell2;
	cell_t* ptr_cell2 = &cell2;

	ptr_cell2->name = "A2";

	printf("\n%s\n", "----------------------------------------");
	printf("%s\n", "------------ TEST NORMAUX --------------");
	printf("%s\n", "----------------------------------------");

	init();

	printf("%s\n", "----- TEST EVALUATION -----");
	evaluate(ptr_cell);
	printf("Résultat attendu -> 27 (5+4)*3 : %f\n", ptr_cell->value);

	printf("%s\n", "----- TEST EVALUATION -----");
	ptr_cell->saisi = string;
	evaluate(ptr_cell);
	printf("Résultat attendu -> 0 : %f\n", ptr_cell->value);

	printf("%s\n", "---- TEST GETREFERENCE ----");
	ptr_listCell = initList();
	ptr_listCell = insertHead(ptr_listCell, ptr_cell);
	ptr_listCell = insertHead(ptr_listCell, ptr_cell2);
	printf("Résultat attendu -> %p : %p\n", (void*)ptr_cell2, getReference(ptr_listCell, "A2"));


	return 0;
}