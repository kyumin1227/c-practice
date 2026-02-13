#include <stdio.h>

int main() {
    void *a;
    double b = 123.3;

    a = &b;

    printf("%lf", *(double *)a);    // double의 포인터로 형 변환 후 메모리를 읽음, 형 변환을 하지 않은 경우 몇 바이트를 읽어야 하는지 모름으로 에러 발생
    return 0;
}