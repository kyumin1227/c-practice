#include <stdio.h>

// 최적의 속도를 위해 메모리를 4의 배수로 맞추는 더블 워드 경계에 놓고 싶지 않을 때 컴파일러에게 명령
#pragma pack(1)

struct Weird {
    char arr[2];
    int i;
};

int main() {
    struct Weird a;
    printf("size of a : %lu \n", sizeof(a));
    return 0;
}