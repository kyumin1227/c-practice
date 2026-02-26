#include <stdio.h>
#include <string.h>

int main() {
    char input_route[20];

    scanf("%s", input_route);

    char route[25];
    strcpy(route, input_route);
    strcat(route, ".txt");

    FILE *fp = fopen(route, "w");

    fputc('a', fp);
    fclose(fp);
    return 0;
}