#include <stdio.h>

int main() {
    char c;
    scanf("%c", &c);
    if (c >= 'a' && c <= 'z')
        printf("입력된 문자는 알파벳 소문자입니다.\n");
    else if (c >= 'A' && c <= 'Z')
        printf("입력된 문자는 알파벳 대문자입니다.\n");
    else if (c >= '0' && c <= '9')
        printf("입력된 문자는 숫자입니다.\n");
    else
        printf("입력된 문자는 특수문자입니다.\n");

    return 0;
}