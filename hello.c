#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	clock_t start, stop;
	double duration;
	start = clock();	// 측정 ?��?��
	for (int i = 0; i < 10000000; i++)	// ?���? ?��?�� 반복 루프
		;
	stop = clock();	// 측정 종료
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("?��?��?��간�?? %f초입?��?��.\n", duration);
	return 0;
}
