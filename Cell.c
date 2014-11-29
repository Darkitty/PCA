#include "Cell.h"

operation_t op[4];

void init() {
	op[0].nom = "+";
	op[0].ptr = &addition;

	op[1].nom = "-";
	op[1].ptr = &subtraction;

	op[2].nom = "*";
	op[2].ptr = &multiplication;

	op[3].nom = "/";
	op[3].ptr = &division;
}

void evaluate(cell_t* cell) {
	char* explode;
	char* string;
	int i;

	list_t list;
	list_t* ptr_list;

	ptr_list = &list;

	ptr_list = initList();

	string = strdup(cell->saisi);
	printf("%s\n", string);

	explode = strtok(string, " ");
	while(explode != NULL) {
		printf("Explode : %s\n", explode);
		if (strtod(explode, NULL) != 0.00)
		{
			token_t* tmp;
			tmp = newDoubleToken(strtod(explode, NULL));
			ptr_list = insertHead(ptr_list, tmp);
			printf("Double : %f\n", ((token_t*)(ptr_list->value))->value.cst);
		}
		else
		{
			for (i = 0; i < 4; ++i)
			{
				if (strcmp(explode, op[i].nom) == 0)
				{
					token_t* tmp;
					tmp = newOperatorToken(op[i].ptr);
					ptr_list = insertHead(ptr_list, tmp);
					printf("Pointeur fonction : %p\n", ((token_t*)(ptr_list->value))->value.ptr);
				}
			}
		}
		explode = strtok(NULL, " ");
	}
	printf("Double : %f\n", ((token_t*)(ptr_list->value))->type);
	viewList(ptr_list);
	cell->tokens = ptr_list;
}

token_t* newDoubleToken(double val) {
	token_t* token;

	token = (token_t*)malloc(sizeof(token_t));

	printf("Token double : %f\n", val);

	token->type = VALUE;
	token->value.cst = val;

	printf("Ref double : %f\n", token->value.cst);
	printf("Token type : %d\n", token->type);

	return token;
}

token_t* newOperatorToken(void (*ptr)(pile_t* eval)) {
	token_t* token;

	token = (token_t*)malloc(sizeof(token_t));

	printf("Token fonction : %p\n", ptr);

	token->type = OPERATOR;
	token->value.ptr = ptr;
	printf("Token type : %d\n", token->type);

	return token;
}

void calculate(cell_t* cell) {
	pile_t* ptr_pile;

	ptr_pile = (pile_t*)malloc(sizeof(pile_t)*80);

	initPile(ptr_pile, strlen(cell->saisi));
}

void addition(pile_t* eval) {
	double res;
	res = unstack(eval) + unstack(eval);
	stack(eval, res);
}

void subtraction(pile_t* eval) {
	double res;
	res = unstack(eval) - unstack(eval);
	stack(eval, res);
}

void multiplication(pile_t* eval) {
	double res;
	res = unstack(eval) * unstack(eval);
	stack(eval, res);
}

void division(pile_t* eval) {
	double res;
	res = unstack(eval) / unstack(eval);
	stack(eval, res);
}

void viewList(list_t* list) {
	list_t* tmp = list;
	int i;
	i = 0;
	while(tmp) {
		if (((token_t*)(tmp->value))->type == 0)
		{
			printf("Element %d : %f\n", i, ((token_t*)(tmp->value))->value);
		}
		else
			printf("Element %d : %p\n", i, ((token_t*)(tmp->value))->value);
		tmp = tmp->next;
		i++;
	}
}