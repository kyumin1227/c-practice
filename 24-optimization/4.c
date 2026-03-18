#include <stdio.h>

int main() {
    int i;
    int n = 10;
    int sum1 = 0, sum2 = 0;
    for (i = 1; i <= n; i++) {
        sum1 += i;
    }

    sum2 = (n + 1) * n / 2;

    printf("sum1 : %d, sum2 : %d", sum1, sum2);
}
