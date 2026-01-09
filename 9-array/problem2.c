#include <stdio.h>

int main() {
    int scores[10];
    int i, j;
    
    for (i = 0; i < 10; i++) {
        printf("학생 %d : ", i + 1);
        scanf("%d", &scores[i]);
    }

    for (i = 0; i < 10; i++) {
        printf("학생 %2d : ", i + 1);
        for (j = 0; j < scores[i] / 10; j++) {
            printf("■");
        }
        printf("\n");
    }
}
