#include <stdio.h>

int IsEqual(char *str_a, char *str_b);

int main() {
    char str_a[] = "abc";
    char str_b[] = "abcd";

    printf("%d", IsEqual(str_a, str_b));
}

int IsEqual(char *str_a, char *str_b) {
    
    int len = 0;
    while (str_a[len] != '\0' || str_b[len] != '\0') {
        if (str_a[len] != str_b[len]) {
            return 0;
        }
        len++;
    }

    return 1;
}