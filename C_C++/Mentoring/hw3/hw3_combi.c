#include <stdio.h>

int main() {
    int total = 0;
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                if (i != j && j != k && i != k) {
                    // printf("%d%d%d ", i, j, k);
                    total++;
                }
            }
    printf("\nTotal number of the combination of digits: %d\n", total);
    
    total = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                if (i > j && j > k) {
                    // printf("%d%d%d ", i, j, k);
                    total++;
                }
            }
    printf("\nTotal number of the permutation of digits: %d\n", total);
    return 0;
}