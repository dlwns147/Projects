#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
    int i,j;

    printf("2부터 100 사이의 소수는 다음과 같습니다.\n");
    
    for (int i=2;i<=100;i++)
    {
        for (j=2;j<i;j++)
        {
            if ((i%j)==0)
                break;
        }

        if (j==i)
            printf("%d ", i);
    }
    return 0;
}
