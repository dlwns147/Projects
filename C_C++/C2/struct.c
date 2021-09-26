#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>

typedef struct {
    int xpos;
    int ypos;
} point;

void input_point(point *p)
{
    printf("x좌표를 입력하세요. : ");
    scanf("%d", &p->xpos);

    printf("y좌표를 입력하세요. : ");
    scanf("%d", &p->ypos);
}

void length (point point1, point point2)
{
    double len = sqrt((point1.xpos - point2.xpos) * (point1.xpos - point2.xpos)
                    + (point1.ypos - point2.ypos) * (point1.ypos - point2.ypos));
    printf("두 점 사이의 거리는 %f 입니다.\n", len);
}

int main(void)
{
    point p1, p2;
    printf("\np1(x, y)의 좌표를 입력합니다.\n");
    input_point(&p1);
    printf("p2(x, y)의 좌표를 입력합니다.\n");
    input_point(&p2);
    length(p1, p2);

    return 0;
}
