#include <stdio.h>

int main() {
    FILE *fp = fopen("some_data.txt", "r");
    char c;

    if (fp == NULL) {
        printf("file open error ! \n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
}