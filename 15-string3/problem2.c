#include <stdio.h>

// 대문자는 소문자로, 소문자는 대문자로 출력하는 함수
void SwapCase(char *str);

int main() {
    char *str1 = {"aBcDE"};
    char *str2 = {"TesT StRinG"};

    SwapCase(str1);
    SwapCase(str2);

    return 0;
}

void SwapCase(char *str) {
    int len = 0;
    while (str[len]) {
        if (str[len] >= 97 && str[len] <= 122) {
            printf("%c", str[len] - 32);
        } else if (str[len] >= 65 && str[len] <= 90) {
            printf("%c", str[len] + 32);
        } else {
            printf("%c", str[len]);
        }
        len++;
    }
    printf("\n");
}