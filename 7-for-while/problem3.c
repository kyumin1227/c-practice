#include <stdio.h>

int main() {
    int sum_num;
    sum_num = 0;
    for (int i = 0; i <= 1000; i++) {
        if (i % 3 == 0 || i % 5 == 5) {
            sum_num += i;
        }
    }
    printf("%d", sum_num);

    return 0;
}