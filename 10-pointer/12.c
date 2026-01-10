// 포인터끼리 덧셈
#include <stdio.h>

int main() {
    int a;
    int* pa = &a;
    int b;
    int* pb = &b;
    int *pc = pa + pb;  // 불가능

    return 0;
}