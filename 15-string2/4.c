#include <stdio.h>

int main() {
    int num, i;
    char c;

    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);

    getchar();

    printf("문자를 입력하세요 : ");
    scanf("%c", &c);

    printf("입력한 문자 : %c", c);

    return 0;
}

// 문자를 입력받을 때는 %c가 아닌 %s를 사용할 것