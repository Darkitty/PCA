#include "List.h"

int main()
{
	list_t* ptr_list;
	ptr_list = (list_t*)malloc(sizeof(list_t));

	initList(ptr_list, "TEST", NULL);

	printf("%p\n", ptr_list);
	printf("%s\n", ptr_list->value);
	printf("%p\n", ptr_list->next);

	insertHead(ptr_list, "TEST2");
	printf("%p\n", ptr_list->next);


	return 0;
}