#include "List.h"

int main()
{
	list_t* ptr_list;
	int retour;

	ptr_list = (list_t*)malloc(sizeof(list_t));

	retour = initList(ptr_list, "TEST", NULL);

	printf("%p\n", ptr_list);
	printf("%s\n", ptr_list->value);
	printf("%p\n", ptr_list->next);

	insertHead(ptr_list, "TEST2");

	printf("Premier element : %p\n", ptr_list->next);

	insertHead(ptr_list->next, "TEST2");
	printf("%s\n", "--------------------------");
	printf("Deuxieme element : %p\n", ptr_list->next->next);


	return 0;
}