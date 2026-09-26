// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// A critical point in a linked list is defined as either a local maxima or a local minima.
// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

// Example 1:
// Input: head = [3,1]
// Output: [-1,-1]
// Explanation: There are no critical points in [3,1].

// Example 2:
// Input: head = [5,3,1,2,5,1,2]
// Output: [1,3]
// Explanation: There are three critical points:
// - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
// - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
// - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
// The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
// The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.

#include <limits.h>
#include<stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

void insert(ListNode** head, int val) {
    ListNode* node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    if (*head) {
        ListNode* curr = *head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = node;
    } else {
        *head = node;
    }
}

int* nodesBetweenCriticalPoints(ListNode* head, int* returnSize) {
    int count = 0;
    int index = 0;
    int prevIndex;

    int firstIndex;
    int minDifference = INT_MAX;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while (head->next) {
        next = head->next;
        if (prev && next) {
            if ((prev->val > head->val && next->val > head->val) 
            || (prev->val < head->val && next->val < head->val)) {
                count += 1;
                if (count == 0) firstIndex = index;
                if (count > 1) {
                    minDifference = (index - prevIndex) < minDifference? (index - prevIndex):minDifference;
                }
                prevIndex = index;
            }
        }
        prev = head;
        head = head->next;
        index++;
    }
    *returnSize = 2;
    int *res = malloc(sizeof(int)*(*returnSize));
    if (count < 2) {
        *res = -1; *(res + 1) = -1;
        return res;
    }

    *res = minDifference;
    *(res + 1) = index - firstIndex;
    return res;
}

void print(ListNode* head) {
    while (head) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    ListNode* head = NULL;
    int array[] = {5, 3, 1, 2, 5, 1, 2};
    int n = sizeof(array)/sizeof(int);
    for (int i = 0; i < n; i++) {
        insert(&head, array[i]);
    }
    print(head);
    int size = 2;
    int *res = nodesBetweenCriticalPoints(head, &size);
    printf("%d, %d\n", *res, *(res+1));
    return 0;
}
