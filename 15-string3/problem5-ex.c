#include <stdio.h>

int add_book(char (*book_name)[30], char (*auth_name)[30],
        char (*publ_name)[30], int *borrowed, int *num_total_book);
int search_book(char (*book_name)[30], char (*auth_name)[30],
        char (*publ_name)[30], int num_total_book, int *borrowed);

int compare(char *str1, char *str2);
int borrow_book(int *borrowed);
int return_book(int *borrowed);
int find(char *str, char *target);

int main() {
    int user_choice;    // 유저가 선택한 메뉴
    int num_total_book = 0; // 현재 책의 수

    char book_name[100][30], auth_name[100][30], publ_name[100][30];
    int borrowed[100];

    while (1) {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");
        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);

        if (user_choice == 1) {
            /* 책을 새로 추가하는 함수 호출 */
            add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
        } else if (user_choice == 2) {
            /* 책을 검색하는 함수 호출 */
            search_book(book_name, auth_name, publ_name, num_total_book, borrowed);
        } else if (user_choice == 3) {
            /* 책을 빌리는 함수 호출 */
            borrow_book(borrowed);
        } else if (user_choice == 4) {
            /* 책을 반납하는 함수 호출 */
            return_book(borrowed);
        } else if (user_choice == 5) {
            /* 프로그램을 종료한다. */
            break;
        }
    }
    return 0;
}

/* 책을 추가하는 함수*/
int add_book(char (*book_name)[30], char (*auth_name)[30],
        char (*publ_name)[30], int *borrowed, int *num_total_book) {

    printf("추가할 책의 제목 : ");
    scanf("%s", book_name[*num_total_book]);
    printf("추가할 책의 저자 : ");
    scanf("%s", auth_name[*num_total_book]);
    printf("추가할 책의 출판사 : ");
    scanf("%s", publ_name[*num_total_book]);
    borrowed[*num_total_book] = 0; /* 빌려지지 않음*/
    printf("추가 완료! \n");
    (*num_total_book)++;
    
    return 0;
}

/* 책을 검색하는 함수 */
int search_book(char (*book_name)[30], char (*auth_name)[30],
        char (*publ_name)[30], int num_total_book, int *borrowed) {

    int user_input; /* 사용자의 입력을 받는다. */
    int i;
    char user_search[30];

    printf("어느 것으로 검색 할 것인가요? \n");
    printf("1. 책 제목 검색 \n");
    printf("2. 지은이 검색 \n");
    printf("3. 출판사 검색 \n");
    scanf("%d", &user_input);
    printf("검색할 단어를 입력해주세요 : ");
    scanf("%s", user_search);
    printf("검색 결과 \n");

    char (*book_info[4])[30] = {NULL, book_name, auth_name, publ_name};

    for (i = 0; i < num_total_book; i++) {
        if (find(book_info[user_input][i], user_search) != -1) {
            printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s // ", i,
                book_name[i], auth_name[i], publ_name[i]);

            if (borrowed[i]) {
                printf("대출됨 \n");
            } else {
                printf("대출 가능 \n");
            }
        }
    }

    return 0;
}

int compare(char *str1, char *str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    if (*str2 == '\0') return 1;
    return 0;
}

int borrow_book(int *borrowed) {
    /* 사용자로 부터 책번호를 받을 변수*/
    int book_num;

    printf("빌릴 책의 번호를 말해주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &book_num);

    if (borrowed[book_num] == 1) {
        printf("이미 대출된 책입니다! \n");
    } else {
        printf("책이 성공적으로 대출되었습니다. \n");
        borrowed[book_num] = 1;
    }

    return 0;
}

int return_book(int *borrowed) {
    /* 반납할 책의 번호 */
    int num_book;

    printf("반납할 책의 번호를 써주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &num_book);

    if (borrowed[num_book] == 0) {
        printf("이미 반납되어 있는 상태입니다\n");
    } else {
        borrowed[num_book] = 0;
        printf("성공적으로 반납되었습니다\n");
    }

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
