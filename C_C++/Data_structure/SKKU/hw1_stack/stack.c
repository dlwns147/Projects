#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// DATA_TYPE == int, defined in "stack.h"
/* FYI, stack_t is defined as below:
	struct stack_t{
		DATA_TYPE size;
		DATA_TYPE top;
		DATA_TYPE *arr;
	}

*/

void init_stack(stack_t* s, int size){

	/* write your own code here. */
//	s = (stack_t *)malloc(sizeof(stack_t));
	s->size = size;
	s->top = 0;
	s->arr = (DATA_TYPE *)malloc(sizeof(DATA_TYPE) * size);

}

bool is_full(stack_t* s){
	bool res;

	/* write your own code here. */
	if (s->size == s->top) res = true;
	else res = false;

	return res;
}

bool is_empty(stack_t* s){
	bool res;

	/* write your own code here. */
	if (!s->top) res = true;
	else res = false;

	return res;
}

DATA_TYPE peek(stack_t* s){
	DATA_TYPE res;

	/* write your own code here. */
	if (!s->top) res = s->size + 1;
	else res = s->arr[s->top-1];

	return res;
}

void push(stack_t* s, DATA_TYPE item){

	/* write your own code here. */
	if (s->top == s->size) printf("Stack is full.\n");
	else s->arr[s->top++] = item;
}

void pop(stack_t* s){

	/* write your own code here. */
	if (!s->top) printf("Stack is empty.\n");
	else s->top--;

}

void print_stack(stack_t* s){

	/* write your own code here. */
	for (int i = 0; i < s->top; i++){
		printf("%d ", s->arr[i]);
		if (i == s->top - 1) printf("\n");
	}
}

/* DO NOT define the main function in this file */