#include <stdio.h>

int main() {
    char str[] = "hello";
    char *pstr = "goodbye";

    str[1] = 'a';
    pstr[1] = 'a';

    return 0;
}