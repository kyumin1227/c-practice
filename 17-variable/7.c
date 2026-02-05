// 지역 변수는 정해진 지역을 벗어나면 소멸
#include <stdio.h>

int* function() {
    int a = 2;
    return &a;
}

int main() {
    int* pa = function();
    printf("%d \n", *pa);

    return 0;
}