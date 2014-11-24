#include "List.h"

int main()
{
	int retour;

	printf("\n%s\n", "----------------------------------------");
	printf("%s\n", "------------ TEST NORMAUX --------------");
	printf("%s\n", "----------------------------------------");
	printf("%s\n", "----- TEST LIST INIT -----");
	initList();

	printf("%s\n", "----- TEST LIST insertQueue -----");
	retour = insertQueue("TEST10");
	printf("Head : %p\n", (void*)ptr_head);
	printf("Retour : %d\n", retour);

	printf("%s\n", "----- TEST LIST insertHead -----");
	retour = insertHead("TEST1");
	printf("Head : %p\n", (void*)ptr_head);
	printf("Retour : %d\n", retour);


	printf("%s\n", "----- TEST LIST insertQueue -----");
	retour = insertQueue("TEST0");
	printf("Head : %p\n", (void*)ptr_head);
	printf("Retour : %d\n", retour);

	printf("%s\n", "----- TEST LIST deleteHead -----");
	retour = insertHead("TEST2");
	printf("Retour : %d\n", retour);

	printf("%s\n", "----- BEFORE -----");
	view();
	deleteHead();	
	printf("%s\n", "----- AFTER -----");
	view();

	deleteValue("TEST1");
	printf("%s\n", "----- AFTER -----");
	view();

	desctructList();
	printf("%s\n", "----- AFTER -----");
	view();

	return 0;
}