#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	clock_t start, stop;
	double duration;
	start = clock();	// ì¸¡ì • ?‹œ?ž‘
	for (int i = 0; i < 10000000; i++)	// ?˜ë¯? ?—†?Š” ë°˜ë³µ ë£¨í”„
		;
	stop = clock();	// ì¸¡ì • ì¢…ë£Œ
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("?ˆ˜?–‰?‹œê°„ì?? %fì´ˆìž…?‹ˆ?‹¤.\n", duration);
	return 0;
}
