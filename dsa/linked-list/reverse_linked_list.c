#include <stdio.h>
#include <stdlib.h>

typedef struct  Node {
    int data;
    struct Node *next;
} Node;

void insert(Node ** head, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (!*head) {
        *head = node;
    } else {
        Node *curr = *head;
        while (curr->next){
            curr = curr->next;
        }
        curr->next = node;
    }
}

void printll(Node *head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node *reverseLinkedList(Node* head) {
    if (head->next == NULL) {
        return head;
    }
    Node *reverse = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return reverse;
}

int main() {
    Node *head  = NULL;
    for (int val = 0; val < 23; val=val+3) {
        insert(&head, val);
    }
    printf("Linked List before reversing:\n");
    printll(head);
    Node *reversedHead = reverseLinkedList(head);
    printf("\nLinked List after reversing:\n");
    printll(reversedHead);
    return 0;
}