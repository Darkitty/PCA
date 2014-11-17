#include "Pile.h"

/**
Test si la pile est vide
Retourne '1' si vrai et '0' sinon
*/
int empty(struct Pile* pile) {
	if (pile.sommmet == -1)
		return 1;
	else
		return 0;
}

/**
Empile un nouveau double dans la pile
Retourne '-1' si la pile est deja remplie
*/
int stack(struct Pile* pile, double element) {
	if ((pile.sommet+1) == pile.MAX)
		return -1;
	pile.sommet++;
	pile.elements + pile.sommet = element;
}

/**
Depile le dernier element de la pile
Retourne '-1' si la pile est vide et le double sinon
*/
double unstack(struct Pile* pile) {
	if (empty(pile) == 1)
		return -1;
	double ret;
	ret = pile.elements + pile.sommet;
	pile.sommet = pile.sommet - 1;
	return ret;
}

int freeSpace(struct Pile* pile) {
	if (empty(pile) == -1)
		return -1;
	return pile.MAX -(pile.sommet + 1);
}

int occupedSpace(struct Pile* pile) {
	if (empty(pile) == -1)
		return -1;
	return (pile.sommet + 1);
}