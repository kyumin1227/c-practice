#include <stdio.h>

// 문자열을 반대로 뒤집는 함수
void FlipDigit(char exp1[], int len);

// 특정 두 문자의 위치를 서로 교환하는 함수
void Swap(char *a, char *b);

// 큰 값을 반환
int Max(int a, int b);

// 덧셈
void Add(char exp1[], int len1, char exp2[], int len2, char result[]);

// 한 자리 덧셈
void SingleAdd(char a, char b, int *c, char *remain);

int main() {

    int i;
    int len1 = 0;
    int len2 = 0;

    char exp1[1000] = {0};
    char exp2[1000] = {0};
    char result[2002] = {0};
    char opt;

    scanf("%s %c %s", exp1, &opt, exp2);

    while (exp1[len1] != '\0') {len1++;}
    while (exp2[len2] != '\0') {len2++;}

    FlipDigit(exp1, len1);
    FlipDigit(exp2, len2);

    Add(exp1, len1, exp2, len2, result);

    if (result[Max(len1, len2)] != '0') {
        printf("%c", result[Max(len1, len2)]);
    }

    for (i = Max(len1, len2) - 1; i > -1; i--) {
        printf("%c", result[i]);
    }
    
}

void FlipDigit(char exp[], int len) {
    int i;
    for (i = 0; i < len / 2; i++) {
        Swap(&exp[i], &exp[len - 1 - i]);
    }
}

void Swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int Max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void Add(char exp1[], int len1, char exp2[], int len2, char result[]) {
    
    int i;
    int c = 0;  // 올림값

    for (i = 0; i < Max(len1, len2); i++) {
        SingleAdd(exp1[i], exp2[i], &c, &result[i]);
    }

    result[Max(len1, len2)] = c + 48;
}

void SingleAdd(char a, char b, int *c, char *remain) {

    int num1 = a - 48;
    int num2 = b - 48;

    if (num1 < 0) {num1 = 0;}
    if (num2 < 0) {num2 = 0;}

    *remain = ((num1 + num2 + *c) % 10) + 48;
    *c = (num1 + num2 + *c) / 10;
}