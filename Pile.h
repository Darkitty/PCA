#ifndef PILE_H
#define PILE_H

#define MAX 50

typedef struct
{
	double* elements;
	int sommet;
	int index;
} pile_t;

int empty(pile_t* pile);

int stack(pile_t* pile, double element);
double unstack(pile_t* pile);

int freeSpace(pile_t* pile);
int occupedSpace(pile_t* pile);

#endif