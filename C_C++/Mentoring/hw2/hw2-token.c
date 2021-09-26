#include <stdio.h>

int main() {
    int amount;
    int t1, t2, t3, t4;
    t1 = t2 = t3 = t4 = 0;

    scanf("%d", &amount);

    if (amount >= 500) {
        t1 = amount / 500;
        amount %= 500;
    }
    if (amount >= 100) {
        t2 = amount / 100;
        amount %= 100;
    }
    if (amount >= 50) {
        t3 = amount / 50;
        amount %= 50;
    }
    if (amount >= 10) {
        t4 = amount / 10;
        amount %= 10;
    }
    printf("500원 : %d 개\n", t1);
    printf("100원 : %d 개\n", t2);
    printf("50원 : %d 개\n", t3);
    printf("10원 : %d 개\n", t4);

    return 0;
}