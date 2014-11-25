#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct list_t list_t;

struct list_t
{
	void* value;
	struct list_t* next;
};

void* initList();

list_t* insertHead(list_t* list, void* value);
list_t* insertQueue(list_t* list, void* value);

list_t* deleteValue(list_t* list, void* value);
list_t* deleteHead(list_t* list);

int operation(int (*fct)(list_t*, void*), list_t* a, void* b);

void view(list_t* list);

int desctructList(list_t* list);

#endif