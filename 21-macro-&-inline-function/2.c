#include <stdio.h>
#define square(x) (x) * (x) // 3 + 1일 경우 ()가 없으면 3 + 1 * 3 + 1 로 치환되어 버림

int main(int argc, char **argv) {
    printf("square(3) : %d \n", square(3 + 1));

    return 0;
}