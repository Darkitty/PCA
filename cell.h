#ifndef CELL_H
#define CELL_H

#include <string.h>
#include <stdlib.h>
#include "List.h"
#include "Pile.h"
#include "Worksheet.h"

typedef struct cell_t cell_t;

struct cell_t
{
	char* saisi;
	double value;
	list_t* tokens;
	list_t* dependancies;
	char* name;
};

typedef struct
{
	enum {VALUE, REF, OPERATOR} type;
	union {
		double cst;
		cell_t* ref;
		void (*ptr)(pile_t* eval);
	} value;
} token_t;

typedef struct
{
	char* nom;
	void (*ptr)(pile_t* eval);
} operation_t;

extern operation_t op[4];

void init();

void evaluate(worksheet_t* worksheet, cell_t* cell);

token_t* newDoubleToken(double val);
token_t* newOperatorToken(void (*ptr)(pile_t* eval));

void addition(pile_t* eval);
void subtraction(pile_t* eval);
void multiplication(pile_t* eval);
void division(pile_t* eval);

void viewList(list_t* list);

void topologicalSorting(cell_t* listCell);
void getDegre(cell_t* listCell);
cell_t* getReference(worksheet_t* worksheet, char* target);

#endif