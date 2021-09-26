#include <stdio.h>
#include "stack.c"

int main(){
	
	stack_t stackA;
	stack_t stackB;
	stack_t stackC;
	init_stack(&stackA, 10);
	init_stack(&stackB, 10);
	init_stack(&stackC, 10);

	// Input number of all elements
	int diskNumber;
	scanf("%d", &diskNumber);

	// Set stack A's elements from 1 to the number of disks.
	for (int i = diskNumber; i > 0; i--) push(&stackA, i);

	char order[4] = { 0, };
	char origin_stack_name, desig_stack_name;
	stack_t *origin_stack, *desig_stack;
	char element_A, element_B, element_C;

	while(order[0] != 'q')
	{
		// Check the moving order.
		origin_stack_name = order[0];
		desig_stack_name = order[2];

		if (origin_stack_name == 'A') origin_stack = &stackA;
		else if (origin_stack_name == 'B') origin_stack = &stackB;
		else if (origin_stack_name == 'C') origin_stack = &stackC;
		else origin_stack = NULL;

		if (desig_stack_name == 'A') desig_stack = &stackA;
		else if (desig_stack_name == 'B') desig_stack = &stackB;
		else if (desig_stack_name == 'C') desig_stack = &stackC;
		else desig_stack = NULL;

		// Confirm whether the moving order is valid.
		if (origin_stack && desig_stack){

			// When stack is empty, function peek returns max value, bigger than any disks.
			// So if origin stack's top element is bigger than or same as designations stack's, then the moving order is invalid.
			if (peek(origin_stack) >= peek(desig_stack)) {
				printf("Invalid move\n");
				scanf(" %[^\n]", order);
				continue;
			}

			else {
				push(desig_stack, peek(origin_stack));
				pop(origin_stack);
			}
		}

		// Print stack A B C's elements.
		printf("  A  B  C\n");			
		for (int i = diskNumber - 1; i >= 0; i--) {

			if (i <= stackA.top) element_A = '0' + stackA.arr[i];
			else element_A = ' ';
			if (i <= stackB.top) element_B = '0' + stackB.arr[i];
			else element_B = ' ';
			if (i <= stackC.top) element_C = '0' + stackC.arr[i];
			else element_C = ' ';
			printf("%3c%3c%3c\n", element_A, element_B, element_C);
		}

		// Input a moving order for loops.
		scanf(" %[^\n]", order);
	}

	free(stackA.arr);
	free(stackB.arr);
	free(stackC.arr);

	return 0;
}