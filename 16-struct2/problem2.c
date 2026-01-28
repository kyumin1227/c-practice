#include <stdio.h>

// .은 필수
struct BigNum {
    int i_digit[100];   // 정수 부분
    int d_digit[100];   // 소수 부분
    int i_total_digit;  // 사용 되고 있는 정수 부분 자리수
    int d_total_digit;  // 사용 되고 있는 소수 부분 자리수
    char sign;          // 부호, 0 이면 양수, 1 이면 음수
};

int InputBigNum(struct BigNum *num);
int Max(int a, int b);
void Add(struct BigNum *num1, struct BigNum *num2, struct BigNum *result);
// 부호는 무시하고 수의 크기만 비교, 앞이 크면 0, 뒤가 크면 1 반환
int Compare(struct BigNum *num1, struct BigNum *num2);
void Subtract(struct BigNum *num1, struct BigNum *num2, struct BigNum *result);

int main() {
    
    int i;
    struct BigNum num1, num2, result;

    printf("첫 번째 숫자를 입력해주세요. \n");
    if (InputBigNum(&num1)) {
        return 1;
    }
    printf("두 번째 숫자를 입력해주세요. \n");
    if (InputBigNum(&num2)) {
        return 1;
    }

    // Add(&num1, &num2, &result);
    Subtract(&num1, &num2, &result);

    if (result.sign) {
        printf("-");
    }

    for (i = result.i_total_digit - 1; i > -1; i--) {
        printf("%d", result.i_digit[i]);
    }

    printf(".");

    for (i = 0; i < result.d_total_digit; i++) {
        printf("%d", result.d_digit[i]);
    }
    
}

int InputBigNum(struct BigNum *num) {
    int i, len = 0;
    char temp[202] = {0};
    scanf("%s", temp);

    if (temp[0] == '-') {
        num->sign = 1;
    } else {
        num->sign = 0;
    }
    
    while (temp[len] != '.') {len++;}
    num->i_total_digit = len - num->sign;

    while (temp[len]) {len++;}
    num->d_total_digit = len - num->i_total_digit - num->sign - 1;

    if (num->i_total_digit > 100 || num->d_total_digit > 100) {
        return 1;
    }

    // 정수 부분은 역순으로 저장
    for (i = 0; i < num->i_total_digit; i++) {
        if (temp[i] < 48 || temp[i] > 57) {return 1;}
        num->i_digit[num->i_total_digit - 1 - i] = temp[i] - 48;
    }

    for (i = 0; i < num->d_total_digit; i++) {
        if (temp[i + num->i_total_digit + 1] < 48 || temp[i + num->i_total_digit + 1] > 57) {return 1;}
        num->d_digit[i] = temp[i + num->i_total_digit + 1] - 48;
    }

    return 0;
}

int Max(int a, int b) {
    return a > b ? a : b;
}

void Add(struct BigNum *num1, struct BigNum *num2, struct BigNum *result) {
    
    int i, temp = 0;
    int d_total_digit = Max(num1->d_total_digit, num2->d_total_digit);
    int i_total_digit = Max(num1->i_total_digit, num2->i_total_digit);

    // 소수 계산
    for (i = d_total_digit - 1; i > -1; i--) {
        int a = (num1->d_total_digit > i) ? num1->d_digit[i] : 0;
        int b = (num2->d_total_digit > i) ? num2->d_digit[i] : 0;

        result->d_digit[i] = (a + b + temp) % 10;
        temp = (a + b + temp) / 10;
    }

    // 정수 계산
    for (i = 0; i < i_total_digit; i++) {
        int a = (num1->i_total_digit > i) ? num1->i_digit[i] : 0;
        int b = (num2->i_total_digit > i) ? num2->i_digit[i] : 0;

        result->i_digit[i] = (a + b + temp) % 10;
        temp = (a + b+ temp) / 10;
    }

    result->d_total_digit = d_total_digit;
    result->i_total_digit = i_total_digit;

    if (temp && i_total_digit < 100) {
        result->i_digit[i_total_digit] = temp;
        result->i_total_digit++;
    }

    result->sign = (num1->sign + num2->sign == 0) ? 0 : 1;

}

int Compare(struct BigNum *num1, struct BigNum *num2) {
    
    if (num1->i_total_digit > num2->i_total_digit) {
        return 0;
    } else if (num1->i_total_digit < num2->i_total_digit) {
        return 1;
    }

    int i;

    for (i = num1->i_total_digit - 1; i >= 0; i--) {
        if (num1->i_digit[i] > num2->i_digit[i]) {
            return 0;
        } else if (num1->i_digit[i] < num2->i_digit[i]) {
            return 1;
        }
    }

    for (i = 0; i < (num1->d_total_digit > num2->d_total_digit ? num2->d_total_digit : num1->d_total_digit); i++) {
        if (num1->d_digit[i] > num2->d_digit[i]) {
            return 0;
        } else if (num1->d_digit[i] < num2->d_digit[i]) {
            return 1;
        }
    }

    if (num1->d_total_digit >= num2->d_total_digit) {
        return 0;
    } else {
        return 1;
    }
}

void Subtract(struct BigNum *num1, struct BigNum *num2, struct BigNum *result) {

    // num1에 큰 값이 들어오도록 재호출
    if (Compare(num1, num2)) {
        return Subtract(num2, num1, result);
    }

    int i, temp = 0;
    result->d_total_digit = Max(num1->d_total_digit, num2->d_total_digit);
    result->i_total_digit = Max(num1->i_total_digit, num2->i_total_digit);

    for (i = result->d_total_digit - 1; i >= 0; i--) {
        int a = (num1->d_total_digit > i) ? num1->d_digit[i] : 0;
        int b = (num2->d_total_digit > i) ? num2->d_digit[i] : 0;
        b += temp;
        
        temp = (a >= b) ? 0 : 1;
        result->d_digit[i] = (a - b + temp * 10) % 10;
    }

    for (i = 0; i < result->i_total_digit; i++) {
        int a = (num1->i_total_digit > i) ? num1->i_digit[i] : 0;
        int b = (num2->i_total_digit > i) ? num2->i_digit[i] : 0;
        b += temp;
        
        temp = (a >= b) ? 0 : 1;
        result->i_digit[i] = (a - b + temp * 10) % 10;
    }

    result->sign = num1->sign;
    
}