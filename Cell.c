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

	pile_t pile;
	pile_t* ptr_pile;

	list_t list;
	list_t* ptr_list;

	ptr_pile = &pile;
	ptr_list = &list;

	initPile(ptr_pile, strlen(cell->saisi));
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
			printf("Double : %f\n", ((token_t*)(ptr_list->value))->type);
		}
		else
		{
			for (i = 0; i < 4; ++i)
			{
				if (strcmp(explode, op[i].nom) == 0)
				{
					ptr_list = insertHead(ptr_list, newOperatorToken(op[i].ptr));
			printf("Double : %f\n", ((token_t*)(ptr_list->value))->type);
				}
			}
		}
		explode = strtok(NULL, " ");
	}
	viewList(ptr_list);
	cell->tokens = ptr_list;
}

token_t* newDoubleToken(double val) {
	token_t token;
	token_t* ptr_token = &token;

	printf("Token double : %f\n", val);

	ptr_token->type = VALUE;
	ptr_token->value.cst = val;

	printf("Ref double : %f\n", ptr_token->value.cst);

	return ptr_token;
}

token_t* newOperatorToken(void (*ptr)(pile_t* eval)) {
	token_t token;
	token_t* ptr_token = &token;

	ptr_token->type = OPERATOR;
	ptr_token->value.ptr = ptr;

	return ptr_token;
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
		printf("Element %d : %f\n", i, ((token_t*)(tmp->value))->type);
		tmp = tmp->next;
		i++;
	}
}