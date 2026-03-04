#include <stdio.h>

int main() {
    FILE *fp = fopen("sample.txt", "r");

    if (fp == NULL) {
        printf("파일이 존재하지 않습니다. \n");
        return 1;
    }

    char c;
    char target[100];

    int i = 0;
    int count = 0;

    printf("찾을 단어 입력 : ");
    scanf("%s", target);

    while ((c = fgetc(fp)) != EOF) {
        if (target[i] == '\0') {
            count++;
            i = 0;
        }

        if (c == target[i]) {
            i++;
        } else {
            i = 0;
        }
    }

    printf("\"%s\" 단어는 해당 파일에서 %d 번 등장 하였습니다. \n", target, count);

    fclose(fp);
}