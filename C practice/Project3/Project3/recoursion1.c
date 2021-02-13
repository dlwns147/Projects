#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int factorial(int i);

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%d", factorial(number));

	return 0;
}

int factorial(int i)
{
	if (i == 1)
	{
		printf("%d번째 팩토리얼\n", i);
		return 1;
	}
	int result = i * factorial(i - 1);
	printf("%d의 팩토리얼은 %d \n", i, result);
	return result;
};
