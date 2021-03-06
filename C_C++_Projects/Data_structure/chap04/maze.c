#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {		// κ΅μ²΄!
	short r;
	short c;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ?€ν μ΄κΈ°???¨μ
void init_stack(StackType *s)
{
	s->top = -1;
}

// κ³΅λ°± ?ν κ²μΆ??¨μ
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ?¬ν ?ν κ²μΆ??¨μ
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// ?½μ?¨μ
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "?€ν ?¬ν ?λ¬\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// ?? ?¨μ
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "?€ν κ³΅λ°± ?λ¬\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ?Όν¬?¨μ
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "?€ν κ³΅λ°± ?λ¬\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== ?€ν μ½λ????===== 


element here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '0', '0', '1' },
{ '1', '0', '0', '0', '1', '1' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },
{ '1', '1', '1', '1', '1', '1' },
};
// ?μΉλ₯??€ν???½μ
void push_loc(StackType *s, int r, int c)
{
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}
// λ―Έλ‘λ₯??λ©΄??μΆλ ₯?λ€. 
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main(void)
{
	int r, c;
	StackType s;

	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s)) {
			printf("?€ν¨\n");
			return 0;
		}
		else
			here = pop(&s);
	}
	printf("?±κ³΅\n");
	return 0;
}