#include <stdio.h>

// 같은면 1, 다르면 0 반환
int compare(char *str1, char *str2);

int main() {
    char str1[100];
    char str2[100];

    scanf("%s %s", str1, str2);

    compare(str1, str2);

    return 0;
}

int compare(char *str1, char *str2) {
    
    while (*str1) {
        if (*str1 != *str2) {
            printf("다르다");
            return 0;
        }
        str1++;
        str2++;
    }

    if (*str2) {
        printf("다르다");
        return 0;
    }

    printf("같다");
    return 1;
}