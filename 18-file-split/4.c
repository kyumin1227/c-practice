#include <stdio.h>
#define A
// #define B

int main() {

    // A가 정의 되면 코드에 포함되고, 정의되지 않으면 코드에 포함되지 않는다
    #ifdef A
    printf("AAAA \n");
    #endif
    #ifdef B
    printf("BBBB \n");
    #endif
    
    #ifdef A
    #else
    #endif

    return 0;
}