#include <stdio.h>

int main() {
    int count = 0;

    for (int a = 0; a < 2000; a++) {
        for (int b = 0; b < a; b++) {
            for (int c = 0; c < b; c++) {
                if (a + b + c == 2000) {
                    count++;
                }
            }
        }
    }

    printf("%d", count);

    return 0;
}