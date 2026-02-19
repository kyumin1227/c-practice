#include <stdio.h>
#define PrintVariableName(var) printf(#var "\n");   // 인자앞에 #을 붙이면 문자열로 변경 시킴

int main(int argc, char **argv) {
    int a;

    PrintVariableName(a);

    return 0;
}