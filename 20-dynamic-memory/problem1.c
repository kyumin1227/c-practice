#include <stdio.h>
#include <stdlib.h>

void get_average(int num_student, int num_subject, int (*scores)[num_student]);
void get_rank(int num_student, int num_subject, int(*scores)[num_student]);

int main(int argc, char **argv) {
    int subject, students;

    printf("과목 수 : ");
    scanf("%d", &subject);

    printf("학생의 수 : ");
    scanf("%d", &students);

    int(*scores)[students];
    scores = (int(*)[students])malloc(students * subject * sizeof(int));

    for (int i = 0; i < subject; i++) {
        printf("과목 %d 의 점수 ---------- \n", i);
        for (int j = 0; j < students; j++) {
            printf("학생 %d 점수 입력 : ", j);
            scanf("%d", &scores[i][j]);
        }
    }

    get_average(students, subject, scores);
    get_rank(students, subject, scores);
    free(scores);

    return 0;
}

void get_average(int num_student, int num_subject, int(*scores)[num_student]) {
    int i, j, sum;

    for (i = 0; i < num_subject; i++) {
        sum = 0;
        for (j = 0; j < num_student; j++) {
            sum += scores[i][j];
        }
        printf("과목 %d 평균 점수 : %d \n", i, sum / num_student);
    }
}

void get_rank(int num_student, int num_subject, int(*scores)[num_student]) {
    int i, j, sum;

    int *averages = (int *)malloc(num_student * sizeof(int));

    for (j = 0; j < num_student; j++) {
        sum = 0;
        for (i = 0; i < num_subject; i++) {
            sum += scores[i][j];
        }
        averages[j] = sum / num_subject;
    }

    for (i = 0; i < num_student; i++) {
        int count = 0;
        int score = averages[i];

        for (j = 0; j < num_student; j++) {
            if (averages[j] > score) count++;
        }
        printf("학생 %d 등수 : %d 등 \n", i, count + 1);
    }

    free(averages);
}