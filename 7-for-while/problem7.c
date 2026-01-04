#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int temp = n;

    while (temp > 1) {
        for (int i = 2; i <= temp; i++) {
            if (temp % i == 0) {
                temp /= i;
                printf("%d ", i);
                break;
            }
        }
    }
}