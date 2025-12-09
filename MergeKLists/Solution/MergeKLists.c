#include "MergeKLists.h"
#include "../ListLib/List.h"
#include <stdlib.h>
#include <stdio.h>

static struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);
void MergeKLists_Main(void)
{
    int array1[3] = { 1,4,5 };
    int dataLength1 = sizeof(array1) / sizeof(array1[0]);
    int* ptrArray1 = array1;
    int array2[3] = { 1,3,4 };
    int dataLength2 = sizeof(array2) / sizeof(array2[0]);
    int* ptrArray2 = array2;
    int array3[2] = { 2,6 };
    int dataLength3 = sizeof(array3) / sizeof(array3[0]);
    int* ptrArray3 = array3;
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;
    struct ListNode* list3 = NULL;
    ArrayToList(ptrArray1, dataLength1, &list1);
    ArrayToList(ptrArray2, dataLength2, &list2);
    ArrayToList(ptrArray3, dataLength3, &list3);
    struct ListNode* lists[3] = { list1, list2, list3 };
    int listsSize = sizeof(lists) / sizeof(lists[0]);
    mergeKLists(lists, listsSize);
}

static struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) 
{
    // Implementation goes here
    return NULL;
}