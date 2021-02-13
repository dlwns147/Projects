#pragma warning(disable:4996)
#include <stdio.h>

void max_student(int * arr, int x, int y){
	int max = x;
	for (int i = x; i <= y; i++){
		if (arr[max] < arr[i])
			max = i;
	}
	printf("%d %d %d 한글", x, y, max);
}


int main(void){
	int x = 15;
	int y = 19;
	int score[20] = { 0, 10, 5, 60, 20, 95, 30, 80, 40, 45, 
					  50, 55, 15, 65, 70, 75, 35, 85, 90, 25};
	
	max_student(score, x , y);

	return 0;
}
