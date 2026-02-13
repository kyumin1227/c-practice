#include <stdio.h>

int main(int argc, char **argv) {
    int num1, num2;
    char *op;

    num1 = ((int) *argv[1]) - 48;
    num2 = ((int) *argv[3]) - 48;
    op = argv[2];

    printf("정답: %d", num1 + num2);

    return 0;
}