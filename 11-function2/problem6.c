#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    int numbers[1000] = {0};

    for (i = 2; i <= n; i++) {
        if (numbers[i] == 0) {
            printf("%d ", i);
            for (j = i; j <= n; j += i) {
                numbers[j]++;
            }
        }
    }
}