#include <stdio.h>

int main() {
    int temp;
    int prev = 1;
    int now = 1;
    int sum = 0;
    
    while (now <= 1000000) {
        if (now % 2 == 0) {
            sum += now;
        }

        temp = now;
        now += prev;
        prev = temp;
    }

    printf("%d", sum);
    return 0;
}