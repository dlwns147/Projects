#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main (void)
{
    int i,j;
    printf("정수 하나를 입력해 주세요. : ");
    scanf("%d", &i);
    
    if (i==1)
        printf("1 은 소수와 합성수 둘 다 아닙니다.\n");
    if (i<=0)
        printf("양수를 입력해 주세요.\n");

    for (j=2;j<i;j++)
    {
        if ((i%j)==0)
        {
            printf("%d 은(는) 합성수 입니다.\n", i);
            printf("%d (으)로 나누어 떨어집니다.\n", j);
            break;
        }
    }

    if (j==i)
        printf("%d 은(는) 소수 입니다.\n", i);

    return 0;
}
