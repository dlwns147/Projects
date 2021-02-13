#pragma warning(disable:4996)
#include <stdio.h>

void max_student(int* arr, int n1, int n2) {
	int max = n1;
	for (int i = n1; i <= n2; i++) {
		if (arr[max] < arr[i])
			max = i;
	}
	printf("%d 번째와 %d 번째 중 가장 점수가 높은 학생은 %d번 째 입니다.", n1, n2, max);
}

int main(void) {
	int x = 15;
	int y = 19;
	int score[20] = { 0, 10, 5, 60, 20, 95, 30, 80, 40, 45,
					  50, 55, 15, 65, 70, 75, 35, 85, 90, 25 };

	max_student(score, x, y);

	return 0;
}
