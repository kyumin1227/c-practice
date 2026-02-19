#include <stdio.h>
#define RADTODEG(x) ((x) * 57.295)

int main(int argc, char **argv) {
    printf("5 rad 는 : %f 도", RADTODEG(5));

    return 0;
}