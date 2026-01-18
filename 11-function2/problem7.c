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

// 뺄셈
void Subtract(char exp1[], int len1, char exp2[], int len2, char result[]);

// 한 자리 뺄셈
void SingleSubtract(char a, char b, int *c, char *remain);

// 비교 함수 (앞이 크면 0, 뒤가 크면 1 반환)
int Compare(char exp1[], int len1, char exp2[], int len2);

// 곱셈
void Multiple(char exp1[], int len1, char exp2[], int len2, char result[]);

// 한 자리 곱셈
void SingleMultiple(char a, char b, int *c, char *remain);

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

    if (opt == '+') {
        Add(exp1, len1, exp2, len2, result);
    } else if (opt == '-') {
        Subtract(exp1, len1, exp2, len2, result);
    } else if (opt == '*') {
        Multiple(exp1, len1, exp2, len2, result);
    }

    for (i = 2001; i > -1; i--) {
        if (result[i] != '\0') {
            printf("%c", result[i]);
        }
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

    if (c > 0) {
        result[Max(len1, len2)] = c + 48;
    }
}

void SingleAdd(char a, char b, int *c, char *remain) {

    int num1 = a - 48;
    int num2 = b - 48;

    if (num1 < 0) {num1 = 0;}
    if (num2 < 0) {num2 = 0;}

    *remain = ((num1 + num2 + *c) % 10) + 48;
    *c = (num1 + num2 + *c) / 10;
}

void Subtract(char exp1[], int len1, char exp2[], int len2, char result[]) {

    int i = 0;
    int c = 0;

    // 대소 비교 후 큰쪽에서 작은 쪽 빼기
    if (Compare(exp1, len1, exp2, len2) == 0) {
        for (i = 0; i < len1; i++) {
            SingleSubtract(exp1[i], exp2[i], &c, &result[i]);
        }
    } else {
        for (i = 0; i < len2; i++) {
            SingleSubtract(exp2[i], exp1[i], &c, &result[i]);
        }
        result[len2] = '-';
    }
}

void SingleSubtract(char a, char b, int *c, char *remain) {
    int num1 = a - 48;
    int num2 = b - 48;

    if (num1 < 0) {num1 = 0;}
    if (num2 < 0) {num2 = 0;}

    if (num1 >= num2 + *c) {
        *remain = num1 - (num2 + *c) + 48;
        *c = 0;
    } else {
        *remain = num1 + 10 - (num2 + *c) + 48;
        *c = 1;
    }
}

int Compare(char exp1[], int len1, char exp2[], int len2) {
    
    if (len1 > len2) {
        return 0;
    } else if (len2 > len1) {
        return 1;
    }

    int i;

    for(i = len1 - 1; i > -1; i--) {
        if (exp1[i] > exp2[i]) {
            return 0;
        } else if (exp2[i] > exp1[i]) {
            return 1;
        }
    }

    return 0;
}

void Multiple(char exp1[], int len1, char exp2[], int len2, char result[]) {

    int i, j;
    int c = 0;

    for (i = 0; i < len2; i++) {
        char temp[2002] = {0};
        int temp_len = 0;
        int result_len = 0;

        for (j = 0; j < len1; j++) {
            SingleMultiple(exp1[j], exp2[i], &c, &temp[i + j]);
        }

        while (result[result_len] != '\0') {result_len++;}
        while (temp[temp_len + i] != '\0') {temp_len++;}

        printf("\nresult : ");

        for (j = 0; j < result_len; j++) {
            printf("%c", result[j]);
        }

        printf("\ntemp : ");

        for (j = 0; j < temp_len + i; j++) {
            printf("%c", temp[j]);
        }

        printf("\n\n");

        Add(result, result_len, temp, temp_len + i, result);
    }
    
}

void SingleMultiple(char a, char b, int *c, char *remain) {
    int num1 = a - 48;
    int num2 = b - 48;

    if (num1 < 0) {num1 = 0;}
    if (num2 < 0) {num2 = 0;}

    *remain = ((num1 * num2 + *c) % 10) + 48;
    *c = (num1 * num2 + *c) / 10;
}
