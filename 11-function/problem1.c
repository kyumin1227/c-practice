#include <stdio.h>

int print_sort(int *parr);

int main() {
    int i;
    int arr[10];

    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    print_sort(arr);

    return 0;
}

int print_sort(int *parr) {
    int i, j, temp;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10 - i - 1; j++) {
            if (parr[j] > parr[j + 1]) {
                temp = parr[j];
                parr[j] = parr[j + 1];
                parr[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", parr[i]);
    }

    return 0;
}