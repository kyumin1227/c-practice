#include <stdio.h>

int main() {
    int i;
    printf("정수를 입력하세요 : ");
    scanf("%d", &i);

    printf("%d를 32로 나누면 : %d \n", i, i / 32);
    printf("%d를 5칸 쉬프트 하면 : %d \n", i, i >> 5);

    return 0;
}