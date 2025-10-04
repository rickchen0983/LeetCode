#include <iostream>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

extern void ArrayToList(int* array, int dataLength, ListNode** outputList);
extern struct ListNode* swapPairs(struct ListNode* head);
extern struct ListNode* createNode(int value);
extern void appendNode(ListNode** head, int value);
extern void searchNode(ListNode* head, int value);
extern void deleteNode(ListNode** head, int value);
