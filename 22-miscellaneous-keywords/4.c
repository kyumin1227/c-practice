// volatile
#include <stdio.h>

typedef struct SENSOR {
    // 감지 되면 1, 안되면 0
    int sensor_flag;
    int data;
} SENSOR;

int main() {
    volatile SENSOR *sensor;    // 컴파일 레빌의 최적화를 수행하지 않을 값에는 volatile을 붙임

    // volatile이 없으면 컴파일러는 sensor_flag의 값을 확인 후 0이면 무한 반복 시킴
    // volatile을 통해서 최적화를 회피하여 매번 sensor_flag 값 체크 수행
    while(!(sensor->sensor_flag)) {

    }

    printf("Data : %d \n", sensor->data);

    return 0;
}