#include <stdio.h>

static inline int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main(int argc, char **argv) {
    printf("3 과 2 중 최대 값은 : %d", max(3, 2));
    return 0;
}