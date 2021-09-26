#include <stdio.h>
#include "stack.c"

int main(){
	stack_t *stack1 = (stack_t *)malloc(sizeof(stack_t));
	stack_t *stack2 = (stack_t *)malloc(sizeof(stack_t));
	stack_t *stack3 = (stack_t *)malloc(sizeof(stack_t));
	init_stack(stack1, 10);
	init_stack(stack2, 10);
	init_stack(stack3, 10);

	int n_disk;
	char order[4] = { 0, };
	scanf("%d", &n_disk);

	for (int i = n_disk; i > 0; i--)
		push(stack1, i);

	while(order[0] != 'q')
	{
		char rod1, rod2;
		stack_t *stk_ptr1, *stk_ptr2;
		rod1 = order[0];
		rod2 = order[2];

		if (rod1 == 'A') stk_ptr1 = stack1;
		else if (rod1 == 'B') stk_ptr1 = stack2;
		else if (rod1 == 'C') stk_ptr1 = stack3;
		else stk_ptr1 = NULL;

		if (rod2 == 'A') stk_ptr2 = stack1;
		else if (rod2 == 'B') stk_ptr2 = stack2;
		else if (rod2 == 'C') stk_ptr2 = stack3;
		else stk_ptr2 = NULL;

		if(stk_ptr1 && stk_ptr2){
			if(peek(stk_ptr1) >= peek(stk_ptr2))
			{
				printf("Invalid move\n");
				scanf(" %[^\n]", order);
				continue;
			}
			else
			{
				push(stk_ptr2, peek(stk_ptr1));
				pop(stk_ptr1);
			}
		}

		printf("  A  B  C\n");			
		for (int i = n_disk; i > 0; i--)
		{
			char A, B, C;
			if (i <=  stack1->top) A = '0' + stack1->arr[i-1];
			else A = ' ';
			if (i <=  stack2->top) B = '0' + stack2->arr[i-1];
			else B = ' ';
			if (i <=  stack3->top) C = '0' + stack3->arr[i-1];
			else C = ' ';
			printf("%3c%3c%3c\n", A, B, C);
		}
		scanf(" %[^\n]", order);
	}

	free(stack1->arr);
	free(stack1);
	free(stack2->arr);
	free(stack2);
	free(stack3->arr);
	free(stack3);	

	return 0;
}