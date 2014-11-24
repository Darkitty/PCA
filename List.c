#include "List.h"

/**
Initialisation de la pile
La tete est fixee a NULL
*/
int initList(list_t* list) {
	list = (list_t*)malloc(sizeof(list_t));
	if (list == NULL)
	{
		return -1;
	}
	list->next = NULL;
	return 0;
}

/**
Insertion d'une nouvelle valeur
en fin de liste
*/
int insertHead(list_t* list, void* value) {
	list_t* newList;
	newList = (list_t*)malloc(sizeof(list_t));
	if (newList == NULL)
	{
		return -1;
	}
	newList->value = value;
	newList->next = list->next;
	list->next = newList;
	return 0;
}

/**
Insertion d'une nouvelle valeur
en debut de liste
*/
int insertQueue(list_t* list, void* value){
	list_t* courrant;
	list_t* newList;

	newList = (list_t*)malloc(sizeof(list_t));
	if (newList == NULL)
	{
		return -1;
	}

	if (list->next != NULL)
	{
		courrant = list->next;
		while (courrant->next != NULL)
			courrant = courrant->next;

		newList->value = value;

		courrant->next = newList;
		newList->next = NULL;
	}
	else
	{
		insertHead(list, value);
	}

	return 0;
}

/**
Supprime la valeur en fin de liste
*/
int deleteHead(list_t* list) {
	list_t* tmp;
	if (list->next == NULL)
	{
		return -1;
	}	
	tmp = list->next;
	list->next = list->next->next;
	free(tmp);
	return 0;
}

/**
Affiche l'ensemble des valeurs de la
liste (de la tete a la queue)
*/
void view(list_t* list) {
	list_t* tmp = list->next;
	while(tmp) {
		printf("%s\n",(char*)tmp->value);
		tmp = tmp->next;
	}
}

/**
Supprime la premiere occurence d'une
valeur donnee dans la liste
*/
int deleteValue(list_t* list, void* value) {
	list_t* courrant;
	list_t* tmp;

	if (list->next != NULL)
	{
		courrant = list->next;
		while (courrant->value != value)
		{
			tmp = courrant;
			courrant = courrant->next;
		}
		if (courrant == list->next)
		{
			deleteHead(list);
		}
		else
		{			
			tmp->next = courrant->next;
			free(courrant);
		}
		return 0;
	}
	else
		return -1;
}

/**
Destruction de l'ensemble des donnees
de la liste
*/
int desctructList(list_t* list) {
	if (list->next != NULL)
	{
		while (list->next != NULL)
		{
			deleteHead(list);
		}
		free(list->next);
		return 0;
	}
	else
		return -1;
}

int operation(int (*fct)(void *, void *), void *a, void *b)
{
  return (*fct)(a, b);
}