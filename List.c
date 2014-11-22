#include "List.h"

void initList() {
	ptr_head = NULL;
}

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
	}
	newList->value = value;

	courrant->next = newList;
	newList->next = NULL;

	return 0;
}

int deleteHead() {
	list_t* tmp;
	tmp = ptr_head;
	ptr_head = ptr_head->next;
	free(tmp);
}

void view() {
	list_t* tmp = ptr_head;
	while(tmp) {
		printf("%s\n",tmp->value);
		tmp = tmp->next;
	}
}

void desctructList(list_t* liste) {

}