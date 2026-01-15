#include <stdio.h>

int recursion(int now, int index);

int main() {
    int n;

    scanf("%d", &n);

    printf("%d", recursion(1, n));
}

int recursion(int now, int index) {
    
    if (index == 1) {
        return now;
    } else {
        return recursion(now * index, index - 1);
    }
}