#include <stdio.h>

int global = 0; // 데이터 영역(Data segment)에 할당

int function() {
    global++;
    return 0;
}

int main() {
    global = 10;
    function();
    printf("%d \n", global);

    return 0;
}