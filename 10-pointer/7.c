// 상수 포인터
#include <stdio.h>

int main() {
    int a;
    int b;
    int* const pa = &a;

    *pa = 3;    // 가능
    pa = &b;    // 불가능

    return 0;
}