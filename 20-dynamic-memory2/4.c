// memmove
#include <stdio.h>
#include <string.h>

int main() {
    char str[50] = "I love Chewing C hahaha";

    // memmove는 memcpy와 달리 메모리 공간이 겹쳐도 가능, 또한 옮겨도 기존의 데이터가 삭제되지 않음
    printf("%s \n", str);
    printf("memmove 이후 \n");
    memmove(str + 23, str + 17, 6);
    printf("%s", str);

    return 0;
}