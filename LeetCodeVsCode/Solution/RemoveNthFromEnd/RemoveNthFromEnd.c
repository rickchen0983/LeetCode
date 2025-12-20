#include "RemoveNthFromEnd.h"
#include "../../ListLib/List.h"
#include <stdlib.h>
#include <stdio.h>

struct ListNode *removeNthFromEnd(struct ListNode *head, int n);
void RemoveNthFromEnd_Main(void)
{
    int array1[5] = {1, 2, 3, 4, 5};
    int dataLength1 = sizeof(array1) / sizeof(array1[0]);
    int *ptrArray1 = array1;
    struct ListNode *list1 = NULL;
    ArrayToList(ptrArray1, dataLength1, &list1);
    removeNthFromEnd(list1, 2);
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    int count = 0;
    struct ListNode *current = head;
    struct ListNode *ptr = head;
    while (current->next != NULL)
    {
        current = current->next;
        count++;
    }
    int target = count - n + 1;
    int index = 0;
    while (index <= target)
    {
        struct ListNode *temp = ptr->next;
        if (index == target - 1)
        {
            ptr->next = ptr->next->next;
            free(temp);
            break;
        }
        if (target == 0)
        {
            head = head->next;
            free(ptr);
            break;
        }
        ptr = ptr->next;
        index++;
    }
    return head;
}
