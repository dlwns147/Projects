#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	clock_t start, stop;
	double duration;
	start = clock();	// μΈ‘μ  ??
	for (int i = 0; i < 10000000; i++)	// ?λ―? ?? λ°λ³΅ λ£¨ν
		;
	stop = clock();	// μΈ‘μ  μ’λ£
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("???κ°μ?? %fμ΄μ??€.\n", duration);
	return 0;
}
