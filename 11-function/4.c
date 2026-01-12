#include <stdio.h>

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}

int main() {
    int a = 3;
    int b = 5;

    swap(&a, &b);

    printf("a : %d, b : %d \n", a, b);

    return 0;
}