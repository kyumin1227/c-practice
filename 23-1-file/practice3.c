#include <stdio.h>

int main() {
    FILE *fp = fopen("a.txt", "r");
    FILE *target = fopen("b.txt", "w");

    int size = 0;

    while (fgetc(fp) != EOF) size++;

    while (size) {
        fseek(fp, --size, SEEK_SET);
        fputc(fgetc(fp), target);
    }

    fclose(fp);
    fclose(target);

    return 0;
}