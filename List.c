#include "List.h"

void initList(list_t* liste, void* value, list_t* next) {
	liste->value = value;
	liste->next = next;
}

void insertHead(list_t* liste, void* value) {
	list_t* newList = (list_t*)malloc(sizeof(list_t));
	newList->value = value;
	ptr_head = newList;
	liste->next = newList;
}

void insertQueue(list_t* liste, void* value){

}

void desctructList(list_t* liste) {

}