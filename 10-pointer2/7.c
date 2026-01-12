#include <stdio.h>

int main() {
    int arr[2][3];
    int brr[10][3];
    int crr[2][5];

    int (*parr)[3];

    parr = arr;
    parr = brr;
    parr = crr; // 열의 크기가 다르기 때문에 오류 발생

    return 0;
}