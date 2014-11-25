#include "List.h"

/**
Initialisation de la pile
La tete est fixee a NULL
*/
void* initList() {
	/*list = (list_t*)malloc(sizeof(list_t));
	printf("%p\n", list);
	if (list == NULL)
	{
		return -1;
	}
	list->next = NULL;
	return 0;*/
	return NULL;
}

/**
Insertion d'une nouvelle valeur
en fin de liste
*/
list_t* insertHead(list_t* list, void* value) {
	list_t* newList;
	newList = (list_t*)malloc(sizeof(list_t));
	if (newList == NULL)
	{
		return NULL;
	}
	newList->value = value;
	newList->next = list;
	list = newList;
	return list;
}

/**
Insertion d'une nouvelle valeur
en debut de liste
*/
list_t* insertQueue(list_t* list, void* value){
	list_t* courrant;
	list_t* newList;

	newList = (list_t*)malloc(sizeof(list_t));
	if (newList == NULL)
	{
		return NULL;
	}

	if (list != NULL)
	{
		courrant = list;
		while (courrant->next != NULL)
			courrant = courrant->next;

		newList->value = value;

		courrant->next = newList;
		newList->next = NULL;
	}
	else
	{
		list = insertHead(list, value);
	}

	return list;
}

/**
Supprime la valeur en fin de liste
*/
list_t* deleteHead(list_t* list) {
	list_t* tmp;
	if (list == NULL)
	{
		return NULL;
	}	
	tmp = list;
	list = list->next;
	free(tmp);
	return list;
}

/**
Affiche l'ensemble des valeurs de la
liste (de la tete a la queue)
*/
void view(list_t* list) {
	list_t* tmp = list;
	while(tmp) {
		printf("%s\n",(char*)tmp->value);
		tmp = tmp->next;
	}
}

/**
Supprime la premiere occurence d'une
valeur donnee dans la liste
*/
list_t* deleteValue(list_t* list, void* value) {
	list_t* courrant;
	list_t* tmp;
	tmp = NULL;

	if (list->next != NULL)
	{
		courrant = list;
		while (courrant != NULL && courrant->value != value)
		{
			tmp = courrant;
			courrant = courrant->next;
		}
		if (courrant == list)
		{
			list = deleteHead(list);
		}
		else
		{			
			tmp->next = courrant->next;
			free(courrant);
		}
		return list;
	}
	else
		return NULL;
}

/**
Destruction de l'ensemble des donnees
de la liste
*/
int desctructList(list_t* list) {
	if (list != NULL)
	{
		while (list != NULL)
		{
			list = deleteHead(list);
		}
		return 0;
	}
	else
		return -1;
}

/**
Application d'une fonction passee en parametre
sur un noeud donne
*/
int operation(int (*fct)(list_t*, void*), list_t* a, void* b)
{
  return (*fct)(a, b);
}