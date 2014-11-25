#include "List.h"

int main()
{
	list_t list;
	list_t* ptr_list = &list;

	printf("\n%s\n", "----------------------------------------");
	printf("%s\n", "------------ TEST NORMAUX --------------");
	printf("%s\n", "----------------------------------------");
	printf("%s\n", "----- TEST LIST INIT -----");
	ptr_list = initList();

	printf("%s\n", "----- TEST LIST insertQueue -----");
	printf("%s\n", "----- BEFORE -----");
	view(ptr_list);
	ptr_list = insertQueue(ptr_list, "TEST10");	
	printf("%s\n", "----- AFTER -----");
	view(ptr_list);

	printf("%s\n", "----- TEST LIST insertHead -----");
	printf("%s\n", "----- BEFORE -----");
	view(ptr_list);
	ptr_list = insertHead(ptr_list, "TEST1");
	printf("%s\n", "----- AFTER -----");
	view(ptr_list);


	printf("%s\n", "----- TEST LIST insertQueue -----");
	printf("%s\n", "----- BEFORE -----");
	view(ptr_list);
	ptr_list = insertQueue(ptr_list, "TEST0");
	printf("%s\n", "----- AFTER -----");
	view(ptr_list);

	printf("%s\n", "----- TEST LIST deleteHead -----");
	printf("%s\n", "----- BEFORE -----");
	view(ptr_list);
	ptr_list = deleteHead(ptr_list);	
	printf("%s\n", "----- AFTER -----");
	view(ptr_list);

	printf("%s\n", "----- TEST LIST deleteValue -----");
	printf("%s\n", "----- BEFORE -----");
	ptr_list = insertHead(ptr_list, "TEST2");
	ptr_list = insertHead(ptr_list, "TEST3");
	view(ptr_list);
	ptr_list = deleteValue(ptr_list, "TEST2");
	printf("%s\n", "----- AFTER -----");
	view(ptr_list);

	printf("%s\n", "----- TEST LIST operation -----");
	operation(&insertQueue, ptr_list, "NULL");
	operation(&view, ptr_list, NULL);

	return 0;
}