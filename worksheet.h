#ifndef WORKSHEET_H
#define WORKSHEET_H

#include "List.h"

typedef struct
{
	char* file_name;
	int columns;
	int lines;
	list_t* cells;
} worksheet_t;

#endif