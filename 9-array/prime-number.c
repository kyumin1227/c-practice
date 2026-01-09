#include <stdio.h>

int main() {
    int guess = 5;
    int prime[1000];

    int i, ok;
    int index = 2;

    prime[0] = 2;
    prime[1] = 3;

    while (1) {

        if (index == 1000) {
            break;
        }
        ok = 0;
        
        for (i = 0; i < index; i++) {
            if (guess % prime[i] == 0) {
                ok++;
                break;
            }
        }

        if (ok == 0) {
            prime[index] = guess;
            index++;
        }
        guess += 2;
    }

    for (i = 0; i < 1000; i++) {
        printf("소수 : %d\n", prime[i]);
    }
}
