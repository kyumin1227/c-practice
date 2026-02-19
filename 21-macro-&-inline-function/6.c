#include <stdio.h>

// 매크로 함수는 단순히 텍스트를 복사하지만, 인라인 함수는 컴파일러가 문맥 및 타입을 분석 후 최적화하기 때문에 디버깅 가능, 즉 매크로 함수 보다 인라인 함수를 권장
static inline int square(int a) { return a * a; }

int main(int argc, char **argv) {
    printf("%d", square(3));

    return 0;
}