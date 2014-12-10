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
	char* name;
	int degree;
	double value;
	list_t* tokens;
	list_t* dependancies;
	list_t* usedBy;
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
void evaluateGraph(worksheet_t* worksheet);

token_t* newDoubleToken(double val);
token_t* newOperatorToken(void (*ptr)(pile_t* eval));

void addition(pile_t* eval);
void subtraction(pile_t* eval);
void multiplication(pile_t* eval);
void division(pile_t* eval);

void viewListCell(list_t* list);
void viewCells(list_t* list);

void topologicalSorting(worksheet_t* worksheet);
void getDegree(worksheet_t* worksheet);

void* getReference(list_t* list, char* name);

#endif