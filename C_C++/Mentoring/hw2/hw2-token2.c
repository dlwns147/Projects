#include <stdio.h>

int main() {
    int amount;
    scanf("%d", &amount);

    int t1 = amount / 500;
    int t2 = (amount % 500) / 100;
    int t3 = ((amount % 500) % 100) / 50;
    int t4 = (((amount % 500) % 100) % 50) / 10;
    
    printf("500원 : %d 개\n", t1);
    printf("100원 : %d 개\n", t2);
    printf("50원 : %d 개\n", t3);
    printf("10원 : %d 개\n", t4);

    return 0;
}