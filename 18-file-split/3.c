// define
#include <stdio.h>
#define VAR 10  // 전처리로 컴파일 이전 VAR은 모두 10으로 대체

int main() {
    char arr[VAR] = {"hi"};
    printf("%s\n", arr);

    return 0;
}