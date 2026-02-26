#include <stdio.h>

int main() {
    fclose(stdout);
    // 표준 출력 스트림을 닫으면 printf를 해도 출력 되지 않음
    printf("aaa");
    return 0;
}