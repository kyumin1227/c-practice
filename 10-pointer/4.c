#include <stdio.h>

int main() {
    int a;
    int *p;

    p = &a;
    *p = 3;

    printf("a의 값 : %d \n", a);
    printf("*p의 값 : %d \n", *p);

    return 0;
}