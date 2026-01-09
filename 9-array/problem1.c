#include <stdio.h>

int main() {
    int scores[10];
    int i, j, temp;
    
    for (i = 0; i < 10; i++) {
        printf("학생 %d : ", i + 1);
        scanf("%d", &scores[i]);
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10 - i - 1; j++) {
            if (scores[j] > scores[j + 1]) {
                temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d\n", scores[i]);
    }
}
