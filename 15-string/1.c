#include <stdio.h>

int main() {
    char null_1 = '\0';
    char null_2 = 0;
    // char null_3 = (char)NULL;   // 컴파일 불가능 

    char not_null = '0';

    printf("Null의 아스키 값 : %d, %d \n", null_1, null_2);
    printf("'0'의 아스키 값 : %d \n", not_null);
}