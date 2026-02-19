#include <stdio.h>

struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};

// 타입을 정의 하면 해당 구조체를 사용할 때 struct HUMAN 뿐만 아닌 Human으로도 이용 가능
typedef struct HUMAN Human; // typedef (이름을 새로 부여하고자 하는 타입) (새로 준 타입의 이름)

int Print_Status(Human human);

int main() {
    Human Adam = {31, 182, 75, 0};
    Human Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);
}

int Print_Status(Human human) {
    if (human.gender == 0) {
        printf("MALE \n");
    } else {
        printf("FEMALE \n");
    }

    printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height, human.weight);

    if (human.gender == 0 && human.height >= 100) {
        printf("HE IS A WINNER!! \n");
    } else if (human.gender == 0 && human.height < 180) {
        printf("HE IS A LOSER \n");
    }

    printf("------------------------------------------- \n");

    return 0;
}