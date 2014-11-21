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

void initList(list_t* liste, void* value, list_t* next);

void insertHead(list_t* liste, void* value);
void insertQueue(list_t* liste, void* value);

void desctructList(list_t* liste);

#endif