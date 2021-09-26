#include <stdio.h>
#include <math.h>
#define N 10
int main() {
    int A[N] = {52, 13, 79, 63, 24, 9, 45, 80, 98, 33};
    int lo, hi, mid, x;
    for (int i = 1; i < N; i++) {
        lo = 0;
        hi = i;
        mid = (lo + hi) / 2;
        x = A[i];
        while (lo < hi) {
            if (x < A[mid]) hi = mid;
            else if (x > A[mid]) lo = mid + 1;
            else break;
            mid = (lo + hi) / 2;
        }

        int j;
        for (j = i; j > mid; j--) A[j] = A[j - 1]; 
        
        A[mid] = x;

        for (j = 0; j < N; j++) printf("%d ", A[j]);
        printf("\n");

    }
    return 0;
}