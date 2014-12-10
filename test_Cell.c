#include "Cell.h"

int main()
{
	cell_t cell;
	cell_t cell2;
	cell_t cell3;
	cell_t cell4;
	worksheet_t worksheet;

	cell_t* ptr_cell;
	cell_t* ptr_cell2;
	cell_t* ptr_cell3;
	cell_t* ptr_cell4;
	worksheet_t* ptr_worksheet;

	char* saisi = "= 3 4 5 + *";
	char* string = "= 2 A1 *";
	char* string2 = "= A2 1 *";
	char* string3 = "= 2 A3 +";

	ptr_cell = &cell;
	ptr_cell2 = &cell2;
	ptr_cell3 = &cell3;
	ptr_cell4 = &cell4;
	ptr_worksheet = &worksheet;

	ptr_cell->saisi = saisi;
	ptr_cell2->saisi = string;
	ptr_cell3->saisi = string2;
	ptr_cell4->saisi = string3;
	ptr_cell->name = "A1";
	ptr_cell2->name = "A2";
	ptr_cell3->name = "A3";
	ptr_cell4->name = "A4";

	ptr_cell->dependancies = initList();
	ptr_cell2->dependancies = initList();
	ptr_cell3->dependancies = initList();
	ptr_cell4->dependancies = initList();
	ptr_cell->usedBy = initList();
	ptr_cell2->usedBy = initList();
	ptr_cell3->usedBy = initList();
	ptr_cell4->usedBy = initList();

	ptr_worksheet->cells = initList();
	ptr_worksheet->cells = insertHead(ptr_worksheet->cells, ptr_cell);
	ptr_worksheet->cells = insertHead(ptr_worksheet->cells, ptr_cell2);
	ptr_worksheet->cells = insertHead(ptr_worksheet->cells, ptr_cell3);
	ptr_worksheet->cells = insertHead(ptr_worksheet->cells, ptr_cell4);

	printf("\n%s\n", "----------------------------------------");
	printf("%s\n", "------------ TEST NORMAUX --------------");
	printf("%s\n", "----------------------------------------");

	init();

	printf("%s\n", "----- TEST EVALUATION -----");
	evaluate(ptr_worksheet, ptr_cell);
	printf("Résultat attendu -> 27 (5+4)*3             : %f\n", ptr_cell->value);

	printf("%s\n", "----- TEST EVALUATION -----");
	evaluate(ptr_worksheet, ptr_cell2);
	printf("Résultat attendu -> 54 2*((5+4)*3)         : %f\n", ptr_cell2->value);

	printf("%s\n", "----- TEST EVALUATION -----");
	evaluate(ptr_worksheet, ptr_cell3);
	printf("Résultat attendu -> 54 1*(2*((5+4)*3))     : %f\n", ptr_cell3->value);

	printf("%s\n", "----- TEST EVALUATION -----");
	evaluate(ptr_worksheet, ptr_cell4);
	printf("Résultat attendu -> 56 3+(1*(2*((5+4)*3))) : %f\n", ptr_cell4->value);

	printf("%s\n", "---- TEST GETREFERENCE ----");
	printf("Résultat attendu A1 -> %p : %p\n", (void*)ptr_cell, (void*)getReference(ptr_worksheet->cells, "A1"));
	printf("Résultat attendu A2 -> %p : %p\n", (void*)ptr_cell2, (void*)getReference(ptr_worksheet->cells, "A2"));
	printf("Résultat attendu A3 -> %p : %p\n", (void*)ptr_cell3, (void*)getReference(ptr_worksheet->cells, "A3"));
	printf("Résultat attendu A4 -> %p : %p\n", (void*)ptr_cell4, (void*)getReference(ptr_worksheet->cells, "A4"));

	printf("%s\n", "------ TEST GETDEGRE ------");
	getDegree(ptr_worksheet);
	printf("Resultat attendu -> 0 : %d\n", ptr_cell->degree);
	printf("Resultat attendu -> 1 : %d\n", ptr_cell2->degree);
	printf("Resultat attendu -> 2 : %d\n", ptr_cell3->degree);
	printf("Resultat attendu -> 1 : %d\n", ptr_cell4->degree);

	printf("%s\n", "----- TEST TOPOLOGIC -----");
	viewCells(ptr_worksheet->cells);
	printf("---\n");
	topologicalSorting(ptr_worksheet);
	evaluateGraph(ptr_worksheet);
	viewCells(ptr_worksheet->graphDep);

	return 0;
}