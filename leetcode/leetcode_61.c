// 61. Rotate List
// Given the head of a linked list, rotate the list to the right by k places.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        Node *curr = *head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

void printLinkedList(Node *head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void print(int data) {
    printf("%d\n", data);
}

Node* rotateRight(Node* head, int k) {
    if (!head || head->next == NULL) return head;
    int size = 0;
    Node *curr = head;
    while (curr) {
        size += 1;
        curr = curr->next;
    }
    int rem = k%size;
    if (rem == 0) {
        return head;
    }

    int startIndex = size - k + 1;
    int counter = 1;
    Node *newHead = NULL;
    Node *node = head;
    while (node) {
        if (counter + 1 == startIndex) {
            newHead = node->next;
            node->next = NULL;
            break;
        }
        counter += 1;
        node = node->next;
    }
    Node *newHeadEnd = newHead;
    while (newHeadEnd->next) {
        newHeadEnd = newHeadEnd->next;
    }
    newHeadEnd->next = head;
    return newHead;
}

int main() {
    Node* head = NULL;
    for(int i = 1; i <=5; i++) {
        insert(&head, i);
    }   
    printLinkedList(head);
    Node *newHead = rotateRight(head, 2);
    printLinkedList(newHead);
    return 0;
}