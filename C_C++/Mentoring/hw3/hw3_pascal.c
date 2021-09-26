#include <stdio.h>

int main() {
    int input, element;
    scanf("%d", &input);
    for (int height = 1; height <= input; height++) {
        for (int blank = 1; blank <= (input - height); blank++)
            printf("   "); // 해당 층의 빈 공백 출력, 기본 단위는 숫자 사이의 공백의 절반
        for (int width = 1; width <= height; width++) {
            if (height == width || width == 1)
                element = 1; // 해당 층의 양 끝 요소는 1
            else 
                element = element * (height - (width - 1)) / (width - 1);
                // 니머지 요소들은 도출해낸 공식에 따라 계산
            printf("% 6d", element);
        }
        printf("\n"); // 줄을 바꾸고 다음층을 출력
    }
    return 0;
}