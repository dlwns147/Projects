#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b; // a는 가로, b는 세로
    scanf("%d %d", &a, &b);

    char** p = malloc(sizeof(char*) * b); // 세로 생성

    for (int i = 0;i <= b - 1;i++) // 가로 생성
    {
        p[i] = malloc((sizeof(char) * a) + 1);
    }

    for (int i = 0; i < b; i++)  // 지뢰밭 생성
    {
        scanf("%s", p[i]);
    }

    for (int i = 0;i <= b - 1;i++)
    {
        for (int j = 0;j <= a - 1;j++)
        {
            if (p[i][j] == '.')
            {
                int c=0;

                if (j > 0) // 왼쪽 지뢰이면
                {
                    if (p[i][j - 1] == '*')
                        c += 1;
                }

                if (j < a - 1) // 오른쪽 지뢰이면
                {
                    if (p[i][j + 1] == '*')
                        c += 1;

                }

                if (i > 0) // 위쪽 지뢰이면
                {
                    if (p[i - 1][j] == '*')
                        c += 1;
                }

                if (i < b - 1) // 아래쪽 지뢰이면
                {
                    if (p[i + 1][j] == '*')
                        c += 1;
                }

                if (j > 0 && i > 0) // 왼쪽위 지뢰이면
                {
                    if (p[i - 1][j - 1] == '*')
                        c += 1;
                }

                if (j > 0 && i < b-1) // 왼쪽아래 지뢰이면
                {
                    if (p[i + 1][j - 1] == '*')
                        c += 1;
                }

                if (j < a-1 && i > 0) // 오른쪽위 지뢰이면
                {
                    if (p[i - 1][j + 1] == '*')
                        c += 1;
                }

                if (j < a-1 && i < b - 1) // 왼쪽아래 지뢰이면
                {
                    if (p[i + 1][j + 1] == '*')
                        c += 1;
                }

                printf("%d", c);

            }
            if (p[i][j] == '*')
                printf("*");
        }
        printf("\n");

    }

    for (int i = 0;i <= a - 1;i++)
    {
        free(p[i]);
    }

    free(p);

    return 0;
}