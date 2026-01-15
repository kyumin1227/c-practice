#include <stdio.h>

int addtion(int *now, int target);
int subtraction(int *now, int target);

int main() {

    int flag, target;
    int result = 0;

    for (;;) {
        printf("덧셈은 1, 뺄셈은 2를 입력해주세요. ");
        scanf("%d", &flag);

        if (flag == 1) {
            printf("현재값 %d에 더할 값을 입력해주세요. ", result);
            scanf("%d", &target);
            addtion(&result, target);
        } else if (flag == 2) {
            printf("현재값 %d에 뺄 값을 입력해주세요. ", result);
            scanf("%d", &target);
            subtraction(&result, target);
        } else {
            printf("현재값은 %d 입니다. \n", result);
        }
    }
    
}

int addtion(int *now, int target) {
    *now += target;

    return 0;
}

int subtraction(int *now, int target) {
    *now -= target;

    return 0;
}