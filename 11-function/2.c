#include <stdio.h>

int factorize(int number) {

    int i;

    while (number > 1) {
        for (i = 2; i <= number; i++) {
            if (number % i == 0) {
                printf("%d ", i);
                number /= i;
                break;
            }
        }
    }

    return 0;
}

int main() {
    factorize(180);

    return 0;
}