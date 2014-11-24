#include "List.h"

/**
Initialisation de la pile
La tete est fixee a NULL
*/
void initList() {
	ptr_head = NULL;
}

/**
Insertion d'une nouvelle valeur
en fin de liste
*/
int insertHead(void* value) {
	list_t* newList;
	newList = (list_t*)malloc(sizeof(list_t));
	if (newList == NULL)
	{
		return -1;
	}
	newList->value = value;
	newList->next = ptr_head;
	ptr_head = newList;
	return 0;
}

/**
Insertion d'une nouvelle valeur
en debut de liste
*/
int insertQueue(void* value){
	list_t* courrant;
	list_t* newList;

	newList = (list_t*)malloc(sizeof(list_t));
	if (newList == NULL)
	{
		return -1;
	}

	if (ptr_head != NULL)
	{
		courrant = ptr_head;
		while (courrant->next != NULL)
			courrant = courrant->next;

		newList->value = value;

		courrant->next = newList;
		newList->next = NULL;
	}
	else
	{
		insertHead(value);
	}

	return 0;
}

/**
Supprime la valeur en fin de liste
*/
int deleteHead() {
	list_t* tmp;
	if (ptr_head == NULL)
	{
		return -1;
	}	
	tmp = ptr_head;
	ptr_head = ptr_head->next;
	free(tmp);
	return 0;
}

/**
Affiche l'ensemble des valeurs de la
liste (de la tete a la queue)
*/
void view() {
	list_t* tmp = ptr_head;
	while(tmp) {
		printf("%s\n",tmp->value);
		tmp = tmp->next;
	}
}

/**
Supprime la premiere occurence d'une
valeur donnee dans la liste
*/
int deleteValue(void* value) {
	list_t* courrant;
	list_t* tmp;

	if (ptr_head != NULL)
	{
		courrant = ptr_head;
		while (courrant->value != value)
		{
			tmp = courrant;
			courrant = courrant->next;
		}
		if (courrant == ptr_head)
		{
			deleteHead();
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