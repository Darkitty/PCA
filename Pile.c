#include "Pile.h"

/**
Initialise la Pile avec MAX cases
Retourne '-1' si jamais le calloc a echoue
* \param pile Adresse de la pile
* \param max Taille maximale de la pile
* \return Le code de retour
*/
int initPile(pile_t* pile, int max) {
	pile->elements = (double* )calloc(max, sizeof(double));
	if (pile->elements == NULL)
	{
		return -1;
	}
	pile->sommet = -1;
	pile->max = max;
	return 0;
}

/**
Test si la pile est vide
Retourne '1' si vrai et '0' sinon
* \param pile Adresse de la pile
* \return Le code de retour
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
* \param pile Adresse de la pile
* \param element Nouvel element a ajouter (type double)
* \return Le code de retour
*/
int stack(pile_t* pile, double element) {
	if ((pile->sommet+1) == pile->max)
		return -1;
	pile->sommet++;
	pile->elements[pile->sommet] = element;
	return 0;
}

/**
Depile le dernier element de la pile
Retourne '-1' si la pile est vide et le double sinon
* \param pile Adresse de la pile
* \return La valeur de l'element depile
*/
double unstack(pile_t* pile) {
	double ret;
	if (empty(pile) == 1)
		return -1;
	ret = pile->elements[pile->sommet];
	pile->sommet = pile->sommet - 1;
	return ret;
}

/**
Retourne le nombre de places restantes
dans la pile
* \param pile Adresse de la pile
* \return Le code de retour
*/
int freeSpace(pile_t* pile) {
	if (empty(pile) == -1)
		return -1;
	return pile->max -(pile->sommet + 1);
}

/**
Retourne le nombre de places occupees
dans la pile
* \param pile Adresse de la pile
* \return Le code de retour
*/
int occupedSpace(pile_t* pile) {
	if (empty(pile) == -1)
		return -1;
	return (pile->sommet + 1);
}