#include <stdio.h>
#define ALIVE 0x1       // 1
#define WALKING 0x2     // 10
#define RUNNING 0x4     // 100
#define JUMPING 0x8     // 1000
#define SLEEPING 0x10   // 10000
#define EATING 0x20     // 100000

int main() {
    int my_status = ALIVE | WALKING | EATING;

    if (my_status & ALIVE) {
        printf("I am ALIVE!! \n");
    }
    if (my_status & WALKING) {
        printf("I am WALKING!! \n");
    }
    if (my_status & RUNNING) {
        printf("I am RUNNING!! \n");
    }
    if (my_status & JUMPING) {
        printf("I am JUMPING!! \n");
    }
    if (my_status & SLEEPING) {
        printf("I am SLEEPING!! \n");
    }
    if (my_status & EATING) {
        printf("I am EATING!! \n");
    }
    return 0;
}