#include <stdio.h>

int main() {
    FILE *fp = fopen("some_data.txt", "r+");
    char c;

    if (fp == NULL) {
        printf("파일 열기를 실패하였습니다. \n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) {
        if (65 <= c && c < 90) {
            fseek(fp, -1, SEEK_CUR);
            fputc(c + 32, fp);
            fseek(fp, 0, SEEK_CUR); // 쓰기 -> 읽기 전환을 위해 fseek 함수 호출
        } else if (97 <= c && c <= 122) {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 32, fp);
            fseek(fp, 0, SEEK_CUR); // 쓰기 -> 읽기 전환을 위해 fseek 함수 호출
        }
    }

    fclose(fp);
}