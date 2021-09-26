#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    // 가장 긴 변 : a
    if (a >= b && a >= c) {
        if (a >= b + c) printf("삼각형이 아닙니다.\n"); // 삼각형의 조건이 아님
        else if ((a * a) > (b * b + c * c)) printf("둔각입니다.\n"); // 둔각 삼각형
        else if ((a * a) == (b * b + c * c)) printf("직각입니다.\n"); // 직각 삼각형
        else printf("acute triangle.\n"); // 예각 삼각형
    }
    // 가장 긴 변 : b
    else if (b >= a && b >= c) {
        if (b >= a + c) printf("삼각형이 아닙니다.\n"); // 삼각형의 조건이 아님
        else if ((b * b) > (a * a + c * c)) printf("둔각입니다.\n"); // 둔각 삼각형
        else if ((b * b) == (a * a + c * c)) printf("직각입니다.\n"); // 직각 삼각형
        else printf("acute triangle.\n"); // 예각 삼각형
    }
    // 가장 긴 변 : c
    else {
        if (c >= a + b) printf("삼각형이 아닙니다.\n"); // 삼각형의 조건이 아님
        else if ((c * c) > (b * b + a * a)) printf("둔각입니다.\n"); // 둔각 삼각형
        else if ((c * c) == (b * b + a * a)) printf("직각입니다.\n"); // 직각 삼각형
        else printf("acute triangle.\n"); // 예각 삼각형
    }
	return 0;
}
