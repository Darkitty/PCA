#include "Pile.h"

void initPile(pile_t* pile, int max) {
	pile->elements = (double*)calloc(max, sizeof(double));
	pile->sommet = -1;
	pile->max = max;
}

/**
Test si la pile est vide
Retourne '1' si vrai et '0' sinon
*/
int empty(pile_t* pile) {
	if (pile->sommet == -1)
		return 1;
	else
		return 0;
}

/**
Empile un nouveau double dans la pile
Retourne '-1' si la pile est deja remplie
*/
int stack(pile_t* pile, double element) {
	if ((pile->sommet+1) == pile->max)
		return -1;
	pile->sommet++;
	pile->elements[pile->sommet] = element;
}

/**
Depile le dernier element de la pile
Retourne '-1' si la pile est vide et le double sinon
*/
double unstack(pile_t* pile) {
	if (empty(pile) == 1)
		return -1;
	double ret;
	ret = pile->elements[pile->sommet];
	pile->sommet = pile->sommet - 1;
	return ret;
}

int freeSpace(pile_t* pile) {
	if (empty(pile) == -1)
		return -1;
	return pile->max -(pile->sommet + 1);
}

int occupedSpace(pile_t* pile) {
	if (empty(pile) == -1)
		return -1;
	return (pile->sommet + 1);
}