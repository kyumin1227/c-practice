#include <stdio.h>

int find(char *str, char *target);

int main() {
    
    char str1[100];
    char str2[100];

    scanf("%s %s", str1, str2);
    printf("%d", find(str1, str2));

    return 0;
}

int find(char *str, char *target) {
    
    int len1 = 0;
    int len2 = 0;

    while (str[len1]) {
        
        if (str[len1] == target[len2]) {
            while (target[len2]) {
                if (str[len1 + len2] != target[len2]) {
                    len2 = 0;
                    break;
                }
                len2++;
            }

            if (len2 != 0) {
                return len1;
            }
        }

        len1++;
    }

    return -1;
}