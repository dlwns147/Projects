#include <stdio.h>

int factorial(int num) {
    if (num == 1 || num == 0) 
        return 1; // 종료 조건
    else
        return num * factorial(num - 1); // 재귀 호출
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d! 은 %d 입니다.", n, factorial(n));
    return 0;
}