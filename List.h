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

list_t* ptr_head;

void initList();

int insertHead(void* value);
int insertQueue(void* value);

int deleteValue();
int deleteHead();

void view();

void desctructList(list_t* liste);

#endif