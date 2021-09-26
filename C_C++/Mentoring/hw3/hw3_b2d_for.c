#include <stdio.h>
#include <math.h>

int main() {
    long binary;
    scanf("%ld", &binary);
    int decimal = 0;
    printf("A binary number %d is ", binary);
    for (int i = 0; binary > 0; i++){
        decimal += (binary % 10) * pow(2, i);
        binary /= 10;
    }
    printf("a decimal number %d.", decimal);
    return 0;
}