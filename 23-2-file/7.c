#include <stdio.h>

int main() {
    FILE *fp = fopen("some_data.txt", "a");
    char c;

    if (fp == NULL) {
        printf("파일 열기를 실패하였습니다! \n");
        return 0;
    }

    fputs("IS ADDED HAHAHAHA", fp);
    fclose(fp);
}