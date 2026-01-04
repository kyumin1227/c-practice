#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        // 공백
        for (int j = 0; j < i; j++) {
            printf(" ");
        }

        // 별
        for (int j = 0; j < n * 2 - i * 2 - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}