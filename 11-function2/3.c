// 상수를 인자로 받기
#include <stdio.h>

int read_val(const int val);

int main() {
    int a;
    scanf("%d", &a);
    read_val(a);
    return 0;
}

int read_val(const int val) {
    val = 5;    // 허용되지 않음
    return 0;
}