#include "DeleteDuplicates.h"
#include "../../ListLib/List.h"
#include <stdlib.h>
#include <stdio.h>

struct ListNode *deleteDuplicates(struct ListNode *head);
void DeleteDuplicates_Main(void)
{
    int array1[4] = {1, 1, 4, 5};
    int dataLength1 = sizeof(array1) / sizeof(array1[0]);
    int *ptrArray1 = array1;
    struct ListNode *list1 = NULL;
    ArrayToList(ptrArray1, dataLength1, &list1);
    deleteDuplicates(list1);
}

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL && current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            struct ListNode *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}
