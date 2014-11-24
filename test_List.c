#include "List.h"

int main()
{
	int retour;
	list_t list;
	list_t* ptr_list = &list;

	printf("\n%s\n", "----------------------------------------");
	printf("%s\n", "------------ TEST NORMAUX --------------");
	printf("%s\n", "----------------------------------------");
	printf("%s\n", "----- TEST LIST INIT -----");
	retour= initList(ptr_list);
	printf("Retour : %d\n", retour);

	printf("%s\n", "----- TEST LIST insertQueue -----");
	retour = insertQueue(ptr_list, "TEST10");
	/*printf("Head : %p\n", (void*)ptr_head);*/
	printf("Retour : %d\n", retour);

	printf("%s\n", "----- TEST LIST insertHead -----");
	retour = insertHead(ptr_list, "TEST1");
	/*printf("Head : %p\n", (void*)ptr_head);*/
	printf("Retour : %d\n", retour);


	printf("%s\n", "----- TEST LIST insertQueue -----");
	retour = insertQueue(ptr_list, "TEST0");
	/*printf("Head : %p\n", (void*)ptr_head);*/
	printf("Retour : %d\n", retour);

	printf("%s\n", "----- TEST LIST deleteHead -----");
	retour = insertHead(ptr_list, "TEST2");
	printf("Retour : %d\n", retour);

	printf("%s\n", "----- BEFORE -----");
	view(ptr_list);
	deleteHead(ptr_list);	
	printf("%s\n", "----- AFTER -----");
	view(ptr_list);

	deleteValue(ptr_list, "TEST1");
	printf("%s\n", "----- AFTER -----");
	view(ptr_list);

	desctructList(ptr_list);

	printf("%s\n", "----- TEST LIST operation -----");
	operation(&insertQueue, ptr_list, "NULL");
	operation(&view, ptr_list, NULL);

	return 0;
}