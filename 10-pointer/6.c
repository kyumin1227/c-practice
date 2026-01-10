// 상수 포인터
#include <stdio.h>

int main() {
    int a;
    int b;
    const int* pa = &a;

    *pa = 3;    // 불가능
    pa = &b;    // 가능

    return 0;
}