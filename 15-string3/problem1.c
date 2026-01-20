#include <stdio.h>

void print_reverse(char *str);

int main() {
    char str[] = {"abcde"};

    print_reverse(str);

}

void print_reverse(char *str) {
    int len = 0;
    while (str[len]) {
        len++;
    }

    while (len) {
        len--;
        printf("%c", str[len]);
    }

    return;
}