#include <stdio.h>

int main() {
    int a = 0xAF;   // 10101111
    int b = 0xB5;   // 10110101

    printf("%x \n", a & b);
    printf("%x \n", a | b);
    printf("%x \n", a ^ b);
    printf("%x \n", a);
    printf("%x \n", ~a);
    printf("%x \n", a << 2);
    printf("%x \n", a >> 3);

    return 0;
}