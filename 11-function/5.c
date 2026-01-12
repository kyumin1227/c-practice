// 함수의 원형
#include <stdio.h>

int swap(int *a, int *b); // 함수 원형 정의

int main() {
    int a = 3;
    int b = 5;

    swap(&a, &b);

    printf("a : %d, b : %d \n", a, b);

    return 0;
}

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}