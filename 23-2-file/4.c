#include <stdio.h>

int main() {
    FILE *fp = fopen("some_data.txt", "r+");    // 읽기 및 쓰기 형식으로 존재하지 않으면 열지 않음
    char data[100];

    fgets(data, 100, fp);
    printf("현재 파일에 있는 내용 : %s \n", data);

    fseek(fp, 5, SEEK_SET);

    fputs("is nothing on this file", fp);

    fclose(fp);
}