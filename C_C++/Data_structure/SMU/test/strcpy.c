#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
	char name[10];
    char stdnum[10];
	int age;
} Student;

int recursive(int n)
{
	 printf("%d, ",n);
 	if (n<1) return -1;
 	else return ( recursive(n-3) + 1 );
}

int main()
{
	int a='a'-'A';
    printf("%c",'C'+a);
}
