#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_TERMS 10
typedef struct{
    int row;
    int col;
    int value;
} element;

typedef struct SparceMatrix{
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
}SparceMatrix;

SparceMatrix M_Transpose(SparceMatrix m)
{
    SparceMatrix a;
    a.cols=m.rows;
    a.rows=m.cols;
    a.terms=m.terms;
    if(m.terms>0)
    {
        int index=0;
        for(int c=0;c<m.cols;c++)
        {
            for (int i=0;i<m.terms;i++)
            {
                if(m.data[i].col==c)
                {
                    a.data[index].col=m.data[i].row;
                    a.data[index].row=m.data[i].col;
                    a.data[index++].value=m.data[i].value;
                }
            }
        }
    }
    return a;
}

void m_print(SparceMatrix m)
{
    for(int i=0;i<m.terms;i++)
        printf("(%d, %d, %d)\n", m.data[i].row, m.data[i].col, m.data[i].value);
}

int main(void)
{
    SparceMatrix m={
        {{0,3,7},{3,0,9},{1,5,8},{1,0,6},{3,1,5},{4,5,1},{5,2,2}},6,7,7};
    SparceMatrix a=M_Transpose(m);
    m_print(a);
    return 0;
}