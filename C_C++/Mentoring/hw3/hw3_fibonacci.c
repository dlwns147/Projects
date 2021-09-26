#include <stdio.h>

int main() {
    int prev = 0; // 이전 단계
    int cur = 1; // 현재 단계
    int n, next;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", cur); // 현재 단계 출력
        // 꼬이지 않게 다음 단계를 새로운 변수에 저장
        next = cur + prev; // 다음 단계 = 이전 단계 + 현재 단계
        prev = cur; // 이전 단계 -> 현재 단계
        cur = next; // 현재 단계 -> 다음 단계
    }
    return 0;
}