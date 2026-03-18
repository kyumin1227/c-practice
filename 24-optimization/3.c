#include <stdio.h>

int main() {
    int i;
    scanf("%d", &i);

    if (i & 1) {
        printf("%d는 홀수 입니다.", i);
    } else {
        printf("%d는 짝수 입니다.", i);
    }
    return 0;
}