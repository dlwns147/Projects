#include <stdbool.h>
#define DATA_TYPE int

typedef struct stack_t{
	DATA_TYPE size;
	DATA_TYPE top;
	DATA_TYPE *arr;
}stack_t;

void init_stack(stack_t*, int); 		//Create stack with user passed size.
bool is_full(stack_t*);			//Check if stack is full, then return TRUE. Otherwise return FALSE.
bool is_empty(stack_t*);		//Check if stack is empty, then return TRUE. Otherwise return FALSE.
DATA_TYPE peek(stack_t*);		//Return top item of stack. Do not remove the item. NOTE, this function will be called only if the stack have at least one item.
void push(stack_t*, DATA_TYPE);	//Push an item at the top of stack. If stack is full, print an error message.
void pop(stack_t*);			//remove an item at the top item of stack. If stack is empty, print an error message.
void print_stack(stack_t*);		//Print all items in the stack by bottom-up order.
