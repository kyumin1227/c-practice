#include <stdio.h>  // 컴파일러가 기본으로 지원하는 헤더파일의 경우 <>
#include "str.h"    // 컴파일러가 기본으로 지원하지 않는 헤더파일의 경우 ""

int main() {
    char str1[20];
    char str2[20];

    scanf("%s", str1);
    scanf("%s", str2);

    if (compare(str1, str2)) {
        printf("%s 와 %s 는 같은 문장입니다. \n", str1, str2);
    } else {
        printf("%s 와 %s 는 다른 문장입니다. \n", str1, str2);
    }
    return 0;
}
