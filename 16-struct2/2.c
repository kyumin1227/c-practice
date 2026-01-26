#include <stdio.h>

struct TEST {
    int c;
    int *pointer;
};

int main() {
    struct TEST t;
    struct TEST *pt = &t;
    int i = 0;

    t.pointer = &i;

    // t.pointer의 값을 가르킴
    // . 의 우선순위가 * 보다 높아 t.pointer가 먼저 해석
    *t.pointer = 3;

    printf("i : %d \n", i);

    // pt가 가르키는 t의 pointer의 값을 변경
    // (*pt).pointer 와 동일
    *pt->pointer = 4;

    printf("i : %d \n", i);

    return 0;
}