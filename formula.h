#ifndef FORMULA_H
#define FORMULA_H

typedef struct
{
	enum {VALUE, REF, OPERATOR} type;
	union {
		double cst;
		cell_t* ref;
		void (*operator)(_stack_t* eval);
	} value;
} token_t;

#endif