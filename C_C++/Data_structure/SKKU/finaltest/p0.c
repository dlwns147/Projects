#if defined(_MSC_VER)
   #define _CRT_SECURE_NO_WARININGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

int Delete(int* arr, int len);

void Make_MaxHeap(int* arr, int len, int i)
{
	if (i >= len) return;
	int l = 2*i+1;
	int r = 2*i+2;
	int max;
	
	if (l < len && arr[l] > arr[i]) max = l;
	else max = i;
	if (r < len && arr[r] > arr[max]) max = r;
	
	if (max != i) {
		int tmp = arr[max];
		arr[max] = arr[i];
		arr[i] = tmp;
		
		/* implement your answer here. Do not change anywhere else. */
		if (max == l) Make_MaxHeap(arr, len, l);
		else if (max == r) Make_MaxHeap(arr, len, r);
	}
}

int main()
{
	int array[N] = {73, 15, 46, 33, 49, 54, 27, 80, 25, 5, 69, 40, 31, 7, 59, 6, 91, 5, 44, 58, 11, 55, 10, 91, 90, 41, 95, 77, 2, 77, 89, 97, 19, 22, 45, 2, 17, 30, 23, 59, 70, 42, 27, 69, 20, 23, 4, 94, 63, 22, 62, 84, 43, 99, 17, 46, 4, 30, 54, 6, 17, 53, 83, 22, 49, 31, 67, 61, 60, 1, 18, 51, 83, 49, 42, 78, 91, 15, 4, 45, 66, 46, 90, 49, 38, 79, 49, 52, 12, 13, 5, 68, 11, 76, 48, 56, 0, 9, 69, 84};
	
	for (int i = N/2-1; i >= 0; i--) Make_MaxHeap(array, N, i);
	
	int score = 0;
	int prev = 100;
	for (int i = N; i > 0; i--) {
		int cur = Delete(array, i);
		if (prev >= cur) {
			prev = cur;
			score++;
		}
	}
	
	if (score == 100) printf("RIGHT!");
	else printf("WRONG!");
	
	return 0;
}

int Delete(int* arr, int len)
{
	int max = arr[0];
	arr[0] = arr[len-1];
	arr[len-1] = -1;

	int i = 0;
	while (true) {
		int l = 2*i+1;
		int r = 2*i+2;
		
		if (l >= len-1 || (arr[i] >= arr[l] && arr[i] >= arr[r])) break;
		else if ((arr[i] >= arr[l] && arr[i] < arr[r]) || (arr[i] < arr[l] && arr[l] < arr[r])) {
			int tmp = arr[i];
			arr[i] = arr[r];
			arr[r] = tmp;
			i = r;
		}
		else if ((arr[i] < arr[l] && arr[i] >= arr[r]) || (arr[i] < arr[r] && arr[r] <= arr[l])) {
			int tmp = arr[i];
			arr[i] = arr[l];
			arr[l] = tmp;
			i = l;
		}
	}
	return max;
}
