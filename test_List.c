#include "List.h"

int main()
{
	int retour;

	printf("%s\n", "----- TEST LIST INIT -----");
	initList();

	printf("%s\n", "----- TEST LIST insertHead -----");
	retour = insertHead("TEST1");
	printf("Head : %p\n", ptr_head);
	printf("Retour : %d\n", retour);


	printf("%s\n", "----- TEST LIST insertQueue -----");
	retour = insertQueue("TEST0");
	printf("Head : %p\n", ptr_head);
	printf("Retour : %d\n", retour);

	printf("%s\n", "----- TEST LIST deleteHead -----");
	retour = insertHead("TEST2");
	printf("Retour : %d\n", retour);

	printf("%s\n", "----- BEFORE -----");
	view();
	deleteHead();	
	printf("%s\n", "----- AFTER -----");
	view();

	return 0;
}