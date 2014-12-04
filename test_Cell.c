#include "Cell.h"

int main()
{
	cell_t cell;
	cell_t cell2;
	worksheet_t worksheet;

	cell_t* ptr_cell;
	cell_t* ptr_cell2;
	worksheet_t* ptr_worksheet;

	char* saisi = "= 3 4 5 + *";
	char* string = "= A2 A1 *";

	ptr_cell = &cell;
	ptr_cell2 = &cell2;
	ptr_worksheet = &worksheet;

	ptr_cell->saisi = saisi;
	ptr_cell->name = "A1";



	ptr_cell2->name = "A2";

	ptr_worksheet->cells = initList();
	ptr_worksheet->cells = insertHead(ptr_worksheet->cells, ptr_cell);
	ptr_worksheet->cells = insertHead(ptr_worksheet->cells, ptr_cell2);

	printf("\n%s\n", "----------------------------------------");
	printf("%s\n", "------------ TEST NORMAUX --------------");
	printf("%s\n", "----------------------------------------");

	init();

	printf("%s\n", "----- TEST EVALUATION -----");
	evaluate(ptr_worksheet, ptr_cell);
	printf("Résultat attendu -> 27 (5+4)*3 : %f\n", ptr_cell->value);

	printf("%s\n", "----- TEST EVALUATION -----");
	ptr_cell->saisi = string;
	evaluate(ptr_worksheet, ptr_cell);
	printf("Résultat attendu -> 0 : %f\n", ptr_cell->value);

	printf("%s\n", "---- TEST GETREFERENCE ----");
	printf("Résultat attendu -> %p : %p\n", (void*)ptr_cell2, (void*)getReference(ptr_worksheet, "A2"));


	return 0;
}