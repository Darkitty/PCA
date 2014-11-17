#ifndef PILE_H
#define PILE_H

#define MAX 50

struct pile
{
	double* elements;
	int sommet;
	int index;
};

int empty(struct Pile* pile);

int stack(struct Pile* pile, double element);
double unstack(struct Pile* pile);

int freeSpace(struct Pile* pile);
int occupedSpace(struct Pile* pile);

#endif