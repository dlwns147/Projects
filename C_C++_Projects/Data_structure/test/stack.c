#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef int element;
typedef struct {
    element *data;
    int capacity;
    int top;
} Stacktype;

void init(Stacktype *s)
{
    s->top=-1;
    s->capacity=1;
    s->data=(element *)malloc(s->capacity * sizeof(element));
}
int empty(Stacktype *s)
{
    return (s->top==-1);
}

int full(Stacktype *s)
{
    return (s->top==(MAX_SIZE-1));
}

void push(Stacktype *s, element item)
{
    if(full(s))
    {
        s->capacity*=2;
		s->data =(element*)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)]=item;
}
element pop(Stacktype *s)
{
    if(empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}
element peek(Stacktype *s)
{
    if(empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)];
}
void drop(Stacktype *s, int t)
{
    if(peek(s)!=t)
        push(s,t);
    else
        (s->top)--;
}

int main(void)
{
    Stacktype S;
    init(&S);
    for(int i=0;i<MAX_SIZE;i++)
        push(&S,i);
    drop(&S,MAX_SIZE);
    printf("%d \n",pop(&S));
    free(S.data);

    return 0;
}

