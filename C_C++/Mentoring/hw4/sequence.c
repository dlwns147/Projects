#include <stdio.h>

void Decrease(int total, int cur, int sum) {
    if (total > sum) {
        printf("%d ", cur);
        for (int i = 1; i <= cur; i++)
            Decrease(total, cur + i, sum + cur + i);
    }
    else
        printf("\n");
}

int main() {
    int input;
    // scanf("%d", &input);
    Decrease(3, 1, 0);
    return 0;
}