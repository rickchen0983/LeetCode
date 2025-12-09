#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

extern void ArrayToList(int* array, int dataLength, struct ListNode** outputList);
extern struct ListNode* swapPairs(struct ListNode* head);
extern struct ListNode* createNode(int value);
extern void appendNode(struct ListNode** head, int value);
extern void searchNode(struct ListNode* head, int value);
extern void deleteNode(struct ListNode** head, int value);
#endif // LIST_H