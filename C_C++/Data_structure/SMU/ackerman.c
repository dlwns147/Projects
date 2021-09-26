#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ack(int m, int n)
{
    if (m == 0)
    {
        printf("%d", n+1);
        //printf("\n");
        return n+1;
    }
    else if (m > 0 && n == 0)
    {
        printf("a(%d, %d)=", m, n);
        return ack(m-1, 1);
    }
    else if (m > 0 && n > 0)
    {
        printf("a(%d, %d)=", m, n);
        return ack(m-1, ack(m, n-1));
    }
}

int main(void)
{
    printf("%d", ack(2, 2));

    return 0;
}