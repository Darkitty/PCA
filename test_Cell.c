#include "Cell.h"

int main()
{
	cell_t cell;
	cell_t* ptr_cell = &cell;
	char* saisi = "= 3 4 5 + *";

	ptr_cell->saisi = saisi;

	init();

	evaluate(ptr_cell);

	calculate(ptr_cell);
	return 0;
}