#include <stdio.h>
#include <stdlib.h>

struct Node* InsertNode(struct Node* current, int data);
void DestroyNode(struct Node* destroy, struct Node* head);
struct Node* CreateNode(int data);
void PrintNodeFrom(struct Node* from);
int CountNode(struct Node* head);
int HasNode(struct Node* head, int target);

struct Node {
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
};

int main() {
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    struct Node* Node4 = InsertNode(Node2, 400);    // Node2 뒤에 Node4 넣기

    PrintNodeFrom(Node1);

    printf("%d \n", CountNode(Node1));
    printf("%d \n", HasNode(Node1, 300));
    return 0;
}

void PrintNodeFrom(struct Node* from) {
    int count = CountNode(from);
    while (count) {
        printf("노드의 데이터 : %d, 현재 노드 : %p, 다음 노드 : %p, 이전 노드 : %p \n", from->data, from, from->nextNode, from->prevNode);
        from = from->nextNode;
        count--;
    }
}

struct Node* InsertNode(struct Node* current, int data) {
    
    struct Node* after = current->nextNode;
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = after;
    newNode->prevNode = current;

    current->nextNode = newNode;
    after->prevNode = newNode;

    return newNode;
}

void DestroyNode(struct Node* destroy, struct Node* head) {
    struct Node* next = head;
    if (destroy == head) {
        if (destroy->nextNode) {
            destroy->nextNode->prevNode = NULL;
        }
        free(destroy);
        return;
    }

    while (next) {
        if (next->nextNode == destroy) {
            destroy->nextNode->prevNode = next;
            next->nextNode = destroy->nextNode;
        }
        next = next->nextNode;
    }
    free(destroy);
}

struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = newNode;
    newNode->prevNode = newNode;

    return newNode;
}

int CountNode(struct Node* head) {
    int count = 1;
    struct Node* next = head->nextNode;
    while (next) {
        if (next == head) {
            break;
        }
        count++;
        next = next->nextNode;
    }

    return count;
}

// 특정 데이터가 존재하면 1, 존재하지 않으면 0 반환
int HasNode(struct Node* head, int target) {
    struct Node *next = head;

    while (next) {
        if (next->data == target) {
            return 1;
        }
        next = next->nextNode;
    }

    return 0;
}