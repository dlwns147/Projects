#include <stdio.h>
#include <math.h>

int main() {
    int decimal;
    scanf("%d", &decimal);
    long binary = 0;
    printf("deicmal number %d is ", decimal); 
    for (int exp = 0; decimal > 0 ; exp++, decimal /= 2) 
        binary += pow(10, exp) * (decimal % 2); // 10진수를 2로 나눈 나머지에 10의 지수를 곱해서 더해준다
        // 반복문의 한 실행이 끝나면 i는 1이 커지고 10진수는 2로 나누어진다.
    printf("binary number %ld.", binary);
    return 0;
}