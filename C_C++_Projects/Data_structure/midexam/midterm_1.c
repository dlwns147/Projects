#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 


int main(void)
{
	StackType* dna_stack;
	StackType* input_stack;


	char dna[100];
	char input[10];

	dna_stack = (StackType*)malloc(sizeof(StackType));
	init_stack(dna_stack);
	input_stack = (StackType*)malloc(sizeof(StackType));
	init_stack(input_stack);

	printf("Please input DNA sequence.: ");
	gets(dna);
	printf("Please input DNA sequence you want to find.:");
	gets(input);

	printf("dna: %s > %s\n", dna, input);


	for (int i = 0; i < strlen(dna); i++)
		push(dna_stack, dna[i]);	// create dna_stack

	for (int i = 0; i < strlen(input); i++)
		push(input_stack, input[i]);	// create input_stack

	while (!is_empty(dna_stack))
	{
		char dna_element = pop(dna_stack);	// pop dna_stack's element

		if (dna_element == peek(input_stack))
		{
			StackType* dna_tmp = (StackType*)malloc(sizeof(StackType));	// create temporary input stack, dna stack2 
			init_stack(dna_tmp);
			StackType* input_tmp = (StackType*)malloc(sizeof(StackType));
			init_stack(input_tmp);
			char input_element = pop(input_stack);	// pop input_stack's element	

			while (input_element == dna_element)
			{
				if (is_empty(dna_stack) || is_empty(input_stack))	// push each input_stack & dna_stack's element to tmp_ipt_stack, tmp_dna_stack
					break;											// while each element is same.
				push(dna_tmp, dna_element);
				push(input_tmp, input_element);
				dna_element = pop(dna_stack);
				input_element = pop(input_stack);
			}

			if (input_element != dna_element)	// if each element is not same,
			{									// put all elements of tmp dna & ipt stack to dna_stack & input_stack.
				push(dna_stack, dna_element);
				push(input_stack, input_element);
				while (!is_empty(dna_tmp))
				{
					push(dna_stack, pop(dna_tmp));
					push(input_stack, pop(input_tmp));
				}
				dna_element = pop(dna_stack);	// delete top element of dna_stack.
			}

			free(dna_tmp);
			free(input_tmp);

			if (is_empty(input_stack))
			{
				printf("The sequence is found!");
				break;
			}
		}

		if (is_empty(dna_stack))
		{
			printf("The sequence is NOT found!");
			break;
		}
	}

	free(dna_stack);
	free(input_stack);
}
