#include <stdio.h>

int copy_str(char *dest, char *src);
int str_add(char *dest, char *src);
// 같으면 1, 다르면 0 반환
int compare(char *dest, char *src);

int main() {
    char str1[] = "hello";
    char str2[] = "hi";

    printf("복사 이전 : %s \n", str1);

    copy_str(str1, str2);

    printf("복사 이후 : %s \n", str1);

    char str3[100] = "Hello my name is ";
    char str4[] = "Kyumin";

    printf("합치기 이전 : %s \n", str3);

    str_add(str3, str4);

    printf("합친 이후 : %s \n", str3);

    char str5[20] = "hello every1";
    char str6[20] = "hello everyone";
    char str7[20] = "hello every1 hi";
    char str8[20] = "hello every1";
    
    if (compare(str5, str6)) {
        printf("%s 와 %s 는 같다 \n", str5, str6);
    } else {
        printf("%s 와 %s 는 다르다 \n", str5, str6);
    }
    if (compare(str5, str7)) {
        printf("%s 와 %s 는 같다 \n", str5, str7);
    } else {
        printf("%s 와 %s 는 다르다 \n", str5, str7);
    }
    if (compare(str5, str8)) {
        printf("%s 와 %s 는 같다 \n", str5, str8);
    } else {
        printf("%s 와 %s 는 다르다 \n", str5, str8);
    }

    return 0;
    
}

int copy_str(char *dest, char *src) {

    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';

    return 1;
}

int str_add(char *dest, char *src) {
    while (*dest) {
        dest++;
    }

    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\n';

    return 1;
}

int compare(char *src1, char *src2) {
    
    while (*src1) {
        if (*src1 != *src2) {
            return 0;
        }
        src1++;
        src2++;
    }

    if (*src2 == '\0') {
        return 1;
    }

    return 0;
    
}