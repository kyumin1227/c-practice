#include <stdio.h>

int main() {
    char sentence_1[4] = {'P', 's', 'i', '\0'};
    char sentence_2[4] = {'P', 's', 'i', 0};
    char sentence_3[4] = {"Psi"};

    printf("sentence_1 : %s \n", sentence_1);
    printf("sentence_2 : %s \n", sentence_2);
    printf("sentence_3 : %s \n", sentence_3);

    return 0;
}