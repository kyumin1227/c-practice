#include <stdio.h>

int gcd(int m, int n);

int main() {
    int n, i;

    printf("몇 개의 수를 입력받나요? ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("두 개 이상의 수를 입력해주세요");
        return 0;
    }

    int numbers[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int result = numbers[0];

    for (i = 1; i < n; i++) {
        result = gcd(result, numbers[i]);
    }

    printf("%d", result);
}

int gcd(int m, int n) {

    int result;
    for (;;) {
        if (m > n) {
            m = m % n;
            if (m == 0) {
                return n;
            }
        } else {
            n = n % m;
            if (n == 0) {
                return m;
            }
        }
    }
}