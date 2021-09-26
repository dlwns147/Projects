#include <stdio.h>
#include <math.h>

int main() {
    long binary;
    scanf("%ld", &binary);
    int i = 0;
    int decimal = 0;
    printf("binary number %d is ", binary);
    while (binary) {
        decimal += (binary % 10) * pow(2, i);
        binary /= 10;
        i++;
    }
    printf("decimal number %d.", decimal);
    return 0;
}