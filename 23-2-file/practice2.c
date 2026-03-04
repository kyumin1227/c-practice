#include <stdio.h>
#include <string.h>

// 특정 단어가 존재하면 1, 존재하지 않으면 0 반환
int check_string(char *target, char *c);

int main() {
    FILE *fp = fopen("sample.txt", "r");

    if (fp == NULL) {
        printf("파일이 존재하지 않습니다.");
        return 1;
    }

    char target[100];

    printf("찾을 단어 입력 : ");
    scanf("%s", target);

    int line_num = 1;
    char c[100];

    while (fgets(c, 100, fp) != NULL) {
        if (check_string(target, c)) {
            printf("%d줄 \n", line_num);
        }
        line_num++;
    }

    fclose(fp);
}

int check_string(char *target, char *c) {

    int i = 0;
    int j = 0;
    int flag = 1;   // 1이면 일치, 0이면 불일치

    while (c[i] != '\n' && c[i] != '\0') {
        if (target[j] == c[i]) {
            while (target[j] != '\0') {
                if (target[j] != c[i + j]) {
                    flag = 0;
                    break;
                }
                j++;
            }

            if (flag) {
                return 1;
            }
        }

        flag = 1;
        j = 0;
        i++;
    }

    return 0;
}