#include <stdio.h>

int CountCola(int money, int price, int bottle, int cur_bottle) {
    int added_bottle;
    if (money >= price) {
        added_bottle = money / price;
        money = money % price;
        return added_bottle + CountCola(money, price, bottle, cur_bottle + added_bottle);
    }
    else if (cur_bottle >= bottle) {
        added_bottle = cur_bottle / bottle;
        cur_bottle = cur_bottle % bottle;
        return added_bottle + CountCola(money, price, bottle, cur_bottle + added_bottle);
    }
    else 
        return 0;
}


int main() {
    int money, price, bottle;
    scanf("%d %d %d", &money, &price, &bottle);
    printf("%d", CountCola(money, price, bottle, 0));
    return 0;
}