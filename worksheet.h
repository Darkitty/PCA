#ifndef WORKSHEET_H
#define WORKSHEET_H

typedef struct
{
	char* file_name;
	int columns;
	int lines;
	list_t* cells;
} worksheet_t;

#endif