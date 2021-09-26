#include <stdio.h>

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    int first = 0;
    int second = 0;
    
    for (int i = 0; i < 10; i++) {
        if (first < arr[i]) {
            second = first;
            first = arr[i];
        }

        else if (second < arr[i]) {
            second = arr[i];
        }
    }

    printf("%d", second);

    return 0;
}