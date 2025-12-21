#include "GetIntersectionNode.h"
#include "../../ListLib/List.h"
#include <stdlib.h>
#include <stdio.h>

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);
struct ListNode *FindNodeByValue(struct ListNode *head, int target);

void GetIntersectionNode_Main(void)
{
    int array1[5] = {4, 1, 8, 4, 5};
    int array2[6] = {5, 6, 1, 8, 4, 5};

    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;

    ArrayToList(array1, 5, &list1);
    ArrayToList(array2, 6, &list2);

    // 🔍 用程式找 list1 中 value == 8 的節點
    struct ListNode *intersectionNode = FindNodeByValue(list1, 8);

    // 🔍 找 list2 中 value == 1 的節點（交會前的最後一個）
    struct ListNode *prev = FindNodeByValue(list2, 1);

    if (intersectionNode && prev)
    {
        prev->next = intersectionNode;
    }

    struct ListNode *result = getIntersectionNode(list1, list2);

    if (result)
        printf("Intersection at node with value: %d\n", result->val);
    else
        printf("No intersection.\n");
}
struct ListNode *FindNodeByValue(
    struct ListNode *head,
    int target)
{
    while (head)
    {
        if (head->val == target)
            return head;
        head = head->next;
    }
    return NULL;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    // 如果其中一個是空的，直接回傳 NULL，不用跑迴圈
    if (headA == NULL || headB == NULL)
        return NULL;

    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;

    while (ptrA != ptrB)
    {
        // 這裡會發生：A 走到末尾變 NULL -> 下一圈變成 headB
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }
    return ptrA;
}
