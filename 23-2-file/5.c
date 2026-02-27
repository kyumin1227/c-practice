// 원칙상 읽기 - 쓰기 모드 전환 시에는 fseek를 호출해야 함으로 현재 코드는 원칙 위반
// fputc 실행 후 fseek 호출 없이 fgetc 실행
#include <stdio.h>

int main() {
    FILE *fp = fopen("some_data.txt", "r+");
    char c;

    if (fp == NULL) {
        printf("파일 열기를 실패하였습니다! \n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) {
        if (65 <= c && c <= 90) {
            fseek(fp, -1, SEEK_CUR);
            fputc(c + 32, fp);
        } else if (97 <= c && c <= 122) {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 32, fp);
        }
    }

    fclose(fp);
}