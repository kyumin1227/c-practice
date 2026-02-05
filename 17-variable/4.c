#include <stdio.h>

int global; // 전역 변수는 정의 시 자동으로 0으로 초기화
int function() {
    global++;
    return 0;
}

int main() {
    function();
    printf("%d \n", global);
    return 0;
}