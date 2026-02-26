#include <stdio.h>

int file_scan(FILE *fp, char *target);

int main() {
    FILE *fp = fopen("a.txt", "r");
    int index = 0;

    char user_input[20];
    scanf("%s", user_input);

    index = file_scan(fp, user_input);

    printf("%d \n", index);

    return 0;
}

int file_scan(FILE *fp, char *target) {

    int index = 0;
    char now = '\0';
    
    while ((now = fgetc(fp)) != EOF) {
        if (now == target[0]) {
            char *p = target + 1;
            int matched = 1;

            while(*p != '\0') {
                char next = fgetc(fp);

                if (*p != next) {
                    matched = 0;
                    break;
                }
                p++;
            }

            if (matched) return index;

            fseek(fp, index + 1, SEEK_SET);
        }
        index++;
    }

    return -1;
}