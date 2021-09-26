#include <stdio.h>
#include <math.h>

int main() {

    int a, b, c;
    double r1, r2;
    printf("이차방정식 a*x^2 + b*x + c = 0의 세 정수 계수를 입력해주세요\n");
    scanf("%d %d %d", &a, &b, &c);
    int d  = b * b - 4 * a * c;

    if (a == 0) printf("이차방정식이 아닙니다.\n"); // 이차방정식 조건 위배.
    else if (d < 0) printf("실근이 존재하지 않습니다.\n"); // 판별식이 음수.
    else if (d == 0) { // 판별식이 0.
        r1 = (double) -b / (double) (2 * a);
        printf("중근 %.2lf이 존재합니다.\n", r1);
    }
    else { // 판별식이 양수.
        r1 = (double) (-b + sqrt(d)) / (double) (2 * a);
        r2 = (double) (-b - sqrt(d)) / (double) (2 * a);
        printf("근 %.2lf 와 근 %.2lf 가 존재합니다.", r1, r2);
    }
}