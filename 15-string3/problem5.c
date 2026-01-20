#include <stdio.h>

void add_book(char books[100][4][100], int *len);
void search_book(char books[100][4][100], int len);
void rent_book(char books[100][4][100], int len);
void return_book(char books[100][4][100], int len);
// 같으면 1, 다르면 0 반환
int compare(char *dest, char *src);

int main() {
    
    int select = 0;
    int books_len = 0;
    char books[100][4][100];    // 제목, 저자, 출판사, 대출 여부

    for (;;) {
        printf("원하시는 메뉴를 선택해주세요. \n");
        printf("1. 도서 추가 \n");
        printf("2. 도서 검색 \n");
        printf("3. 도서 대출 \n");
        printf("4. 도서 반납 \n");
        printf("5. 종료 \n");

        scanf("%d", &select);

        if (select == 1) {
            add_book(books, &books_len);
        } else if (select == 2) {
            search_book(books, books_len);
        } else if (select == 3) {
            rent_book(books, books_len);
        } else if (select == 4) {
            return_book(books, books_len);
        } else if (select == 5) {
            break;
        } else {
            printf("잘못된 값이 입력되었습니다. 1 ~ 5 사이의 값을 입력해주세요. \n");
        }
    }
}

void add_book(char books[100][4][100], int *len) {
    
    printf("추가할 도서의 제목 : ");
    scanf("%s", books[*len][0]);
    printf("추가할 도서의 저자 : ");
    scanf("%s", books[*len][1]);
    printf("추가할 도서의 출판사 : ");
    scanf("%s", books[*len][2]);
    books[*len][3][0] = 'Y';    // 대출 가능
    *len += 1;
}

void search_book(char books[100][4][100], int len) {
    
    int select;
    printf("1. 제목 검색 \n2. 저자 검색 \n3. 출판사 검색");
    scanf("%d", &select);

    if (select > 3 && select < 1) {
        printf("잘못된 값이 입력되었습니다. \n");
        return;
    }
    
    printf("찾으시는 도서를 입력해주세요. \n");
    char input[100];
    scanf("%s", input);

    for (int i = 0; i < len; i++) {
        if (compare(books[i][select - 1], input)) {
            printf("번호 : %d, 도서 제목 : %s, 도서 저자 : %s, 도서 출판사 : %s 대출 여부 ; %s \n", len, books[i][0], books[i][1], books[i][2], books[i][3]);
        }
    }
}

void rent_book(char books[100][4][100], int len) {
    
    int select_book_id;
    printf("대출할 도서의 번호를 입력해주세요 : ");
    scanf("%d", &select_book_id);

    if (select_book_id >= len) {
        printf("존재하지 않는 도서입니다. \n");
    } else if (books[select_book_id][3][0] == 'Y') {
        books[select_book_id][3][0] = 'N';
        printf("대출되었습니다. \n");
    } else if (books[select_book_id][3][0] == 'N') {
        printf("이미 대출 된 도서입니다. \n");
    }
}

void return_book(char books[100][4][100], int len) {

    int select_book_id;
    printf("반납할 도서의 번호를 입력해주세요 : ");
    scanf("%d", &select_book_id);

    if (select_book_id >= len) {
        printf("존재하지 않는 도서입니다. \n");
    } else if (books[select_book_id][3][0] == 'Y') {
        printf("대출 되지 않은 도서입니다. \n");
    } else if (books[select_book_id][3][0] == 'N') {
        books[select_book_id][3][0] = 'Y';
        printf("반납 되었습니다. \n");
    }
}

int compare(char *src1, char *src2) {
    
    while (*src1) {
        if (*src1 != *src2) {
            return 0;
        }
        src1++;
        src2++;
    }

    if (*src2 == '\0') {
        return 1;
    }

    return 0;
    
}
