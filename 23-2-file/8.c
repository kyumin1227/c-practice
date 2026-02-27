#include <stdio.h>

int main() {
    FILE *fp = fopen("some_data.txt", "r");
    char data[100];

    if (fp == NULL) {
        printf("파일 열기 오류! \n");
        return 0;
    }

    printf("---- 입력 받은 단어들 ---- \n");

    // fscanf = 임의의 스트림에서도 입력을 받을수 있는 scanf 보다 조금 더 일반화된 함수
    // fscanf(stdin, "%s", data) 처럼 이용하면 scanf 와 동일하게 사용 가능
    while (fscanf(fp, "%s", data) != EOF) {
        printf("%s \n", data);
    }

    fclose(fp);
}