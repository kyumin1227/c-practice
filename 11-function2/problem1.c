#include <stdio.h>

void Bubble_sort(int* arr, int num_elements);
void swap(int* pele);

int main() {
    int i;
    int math, korea, english;
    int avg, temp;
    int sum = 0;
    int arr[5];

    for (i = 0; i < 5; i++) {
        printf("학생 %d 성적 입력 (수학, 국어, 영어) : ", i + 1);
        scanf("%d %d %d", &math, &korea, &english);
        temp = (math + korea + english) / 3;
        sum += temp;
        arr[i] = temp;
    }

    avg = sum / 5;

    Bubble_sort(arr, 5);

    for (i = 4; i >= 0; i--) {
        if (arr[i] >= avg) {
            printf("평균 %d점 학생 합격 \n", arr[i]);
        } else {
            printf("평균 %d점 학생 불합격 \n", arr[i]);
        }
    }
    
}

void Bubble_sort(int* arr, int num_elements) {
    int i, j;

    for (i = 0; i < num_elements; i++) {
        for (j = 0; j < num_elements - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j]);
            }
        }
    }

    return;
}

void swap(int* pele) {
    int temp = *pele;
    int *next = pele + 1;

    *pele = *next;
    *next = temp;

    return;
}