#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b; // a�� ����, b�� ����
    scanf("%d %d", &a, &b);

    char** p = malloc(sizeof(char*) * b); // ���� ����

    for (int i = 0;i <= b - 1;i++) // ���� ����
    {
        p[i] = malloc((sizeof(char) * a) + 1);
    }

    for (int i = 0; i < b; i++)  // ���ڹ� ����
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

                if (j > 0) // ���� �����̸�
                {
                    if (p[i][j - 1] == '*')
                        c += 1;
                }

                if (j < a - 1) // ������ �����̸�
                {
                    if (p[i][j + 1] == '*')
                        c += 1;

                }

                if (i > 0) // ���� �����̸�
                {
                    if (p[i - 1][j] == '*')
                        c += 1;
                }

                if (i < b - 1) // �Ʒ��� �����̸�
                {
                    if (p[i + 1][j] == '*')
                        c += 1;
                }

                if (j > 0 && i > 0) // ������ �����̸�
                {
                    if (p[i - 1][j - 1] == '*')
                        c += 1;
                }

                if (j > 0 && i < b-1) // ���ʾƷ� �����̸�
                {
                    if (p[i + 1][j - 1] == '*')
                        c += 1;
                }

                if (j < a-1 && i > 0) // �������� �����̸�
                {
                    if (p[i - 1][j + 1] == '*')
                        c += 1;
                }

                if (j < a-1 && i < b - 1) // ���ʾƷ� �����̸�
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