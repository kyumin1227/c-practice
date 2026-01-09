#include <stdio.h>

int main() {
    int arr[5];
    int i, avg = 0;

    for (i = 0; i < 5; i++) {
        printf("%d 번째 학생의 성적을 입력하세요 : ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 5; i++) {
        avg += arr[i];
    }

    printf("전체 학생의 평균은 : %d \n", avg / 5);

    return 0;
}