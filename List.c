#include "List.h"

void initList(list_t* liste, void* value, list_t* next) {
	liste->value = value;
	liste->next = next;
}

int insertHead(list_t* liste, void* value) {
	list_t* newList;
	newList = (list_t*)malloc(sizeof(list_t));
	if (newList == NULL)
	{
		return -1;
	}
	newList->value = value;
	ptr_head = newList;
	liste->next = newList;
	return 0;
}

int insertQueue(list_t* liste, void* value){

}

void desctructList(list_t* liste) {

}