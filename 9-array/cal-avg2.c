#include <stdio.h>

int main() {
    int i, avg, sum = 0;
    int arr[10];

    for (i = 0; i < 10; i++) {
        printf("%d 번째 학생의 성적 : ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    avg = sum / 10;
    printf("전체 학생의 평균은 %d 점 입니다.\n", avg);

    for (i = 0; i < 10; i++) {
        printf("학생 %d : ", i + 1);
        if (arr[i] >= avg) {
            printf("합격\n");
        } else {
            printf("불합격\n");
        }
    }
    
    return 0;
}