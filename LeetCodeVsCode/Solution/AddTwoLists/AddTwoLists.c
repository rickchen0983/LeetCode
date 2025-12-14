#include "../../ListLib/List.h"
#include <stdlib.h>
#include <stdio.h>

#include "AddTwoLists.h"

static struct ListNode *addTwoLists(struct ListNode *list1, struct ListNode *list2);

void AddTwoList_Main(void)
{
    int array1[7] = {9, 9, 9, 9, 9, 9, 9};
    int dataLength1 = sizeof(array1) / sizeof(array1[0]);
    int *ptrArray1 = array1;
    int array2[4] = {9, 9, 9, 9};
    int dataLength2 = sizeof(array2) / sizeof(array2[0]);
    int *ptrArray2 = array2;
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;
    ArrayToList(ptrArray1, dataLength1, &list1);
    ArrayToList(ptrArray2, dataLength2, &list2);
    addTwoLists(list1, list2);
}

static struct ListNode *addTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *ptr;
    struct ListNode *head;
    struct ListNode *new_data;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));

    head->next = NULL;
    ptr = head;
    int carry = 0;

    while (list1 || list2 || carry != 0)
    {
        int value1 = (list1 != NULL) ? list1->val : 0;
        int value2 = (list2 != NULL) ? list2->val : 0;

        new_data = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_data->val = (value1 + value2 + carry) % 10;
        carry = (value1 + value2 + carry) / 10;
        ptr->next = new_data;
        new_data->next = NULL;
        ptr = ptr->next;
        list1 = (list1 != NULL) ? list1->next : list1;
        list2 = (list2 != NULL) ? list2->next : list2;
    }

    return head->next;
}