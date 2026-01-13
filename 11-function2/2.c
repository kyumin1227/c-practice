// 2차원 배열의 각 원소를 1 씩 증가시키는 함수
#include <stdio.h>

// 열의 개수가 2개인 2차원 배열과, 총 행의 수를 인자로 받음 
int add1_element(int (*arr)[2], int row);

int main() {
    int arr[3][2];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    add1_element(arr, 3);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("arr[%d][%d] : %d \n", i, j, arr[i][j]);
        }
    }

    return 0;
}

int add1_element(int (*arr)[2], int row) {  // 함수의 인자인 경우 int arr[][2] 로도 가능
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < 2; j++) {
            arr[i][j]++;
        }
    }

    return 0;
}