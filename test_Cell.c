#include "Cell.h"

int main()
{
	cell_t cell;
	cell_t* ptr_cell = &cell;
	char* saisi = "= 3 4 5 + *";
	char* string = "pca pca";

	ptr_cell->saisi = saisi;

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



	return 0;
}