#include <stdio.h>

int main() {
    char str[30];
    int upper, lower, special, num;
    upper = lower = special = num = 0;
    scanf("%s", str);
    for (int i = 0; (i < 30) && (str[i] != 0); i++) {
        if (str[i] >= '0' && str[i] <= '9')
            num++;
        else if (str[i] >= 'a' && str[i] <= 'z')
            lower++;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            upper++;
        else 
            special++;
    }
    printf("Alphabet uppercase : %d\nAlphabet lowercase : %d\nNumber : %d\nSpecial letter : %d", upper, lower, num, special);

    return 0;
}