#ifndef CELL_H
#define CELL_H

typedef struct
{
	char* saisi;
	double value;
	list_t* tokens;
	cell_t* dependancies;
} cell_t;

#endif