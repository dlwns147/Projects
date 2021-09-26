#include <stdio.h>
#include <math.h>

int main() {
    int decimal;
    scanf("%d", &decimal);
    long binary = 0;
    int i = 0;
    printf("deicmal number %d is ", decimal);
    while (decimal > 0) {
        binary += pow(10, i) * (decimal % 2);
        decimal /= 2;
        i++;
    }
    printf("binary number %ld.", binary);
    return 0;
}