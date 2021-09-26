#if defined(_MSC_VER)
	#define _CRT_SECURE_NO_WARININGS
#endif

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 100

typedef int DATA_TYPE;
void push(DATA_TYPE item);
DATA_TYPE pop();

DATA_TYPE STACK[STACK_MAX];
DATA_TYPE top=0;

int main(){
	int A=10, B=20;
	printf("before swap: A=%d B=%d\n",A,B);
	// swap A and B using ONLY STACK operations, push() and pop() 
	// DO NOT use any temporary variables.

	push(A);
	push(B);
	A = pop();
	B = pop();

	/* implement your answer here */

	printf("after swap: A=%d B=%d\n",A,B);

	return 0;
}

void push(DATA_TYPE item){
	if(top==STACK_MAX-1){
		printf("STACK is full.\n");
		exit(1);
	}
	STACK[top++]=item;
}

DATA_TYPE pop(){
	if(top==0){
		printf("STACK is empty.\n");
		exit(1);
	}
	return STACK[--top];
}

