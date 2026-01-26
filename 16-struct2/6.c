// 구조체를 인자로 전달하기 (제대로 전달되지 않음)
#include <stdio.h>

struct TEST {
    int age;
    int gender;
};

int set_human(struct TEST a, int age, int gender);

int main() {
    struct TEST human;
    set_human(human, 10, 1);
    printf("AGE : %d // Gender : %d ", human.age, human.gender);
    return 0;
}

int set_human(struct TEST a, int age, int gender) {
    a.age = age;
    a.gender = gender;
    return 0;
}