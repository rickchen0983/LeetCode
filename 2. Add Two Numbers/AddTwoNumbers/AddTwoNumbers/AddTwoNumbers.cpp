// MergeTwoSortedLists.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;
};

void ArrayToList(int* array, int dataLength, ListNode** outputList);
ListNode* addTwoLists(struct ListNode* list1, struct ListNode* list2);
void Swap(int* a, int* b);
void SortList(ListNode* head);

int main()
{
    int array1[3] = { 2,4,3 };
    int dataLength1 = sizeof(array1) / sizeof(array1[0]);
    int* ptrArray1 = array1;
    int array2[3] = { 5,6,4 };
    int dataLength2 = sizeof(array2) / sizeof(array2[0]);
    int* ptrArray2 = array2;
    ListNode* list1 = NULL;
    ListNode* list2 = NULL;
    ArrayToList(ptrArray1, dataLength1, &list1);
    ArrayToList(ptrArray2, dataLength2, &list2);
    addTwoLists(list1, list2);
}

void ArrayToList(int* array, int dataLength, ListNode** outputList)
{
    ListNode* ptr;
    ListNode* head;
    ListNode* new_data;
    head = (ListNode*)malloc(sizeof(ListNode));

    head->next = NULL;
    ptr = head;
    for (int i = 0; i < dataLength; i++)
    {
        new_data = (ListNode*)malloc(sizeof(ListNode));
        new_data->val = array[i];
        ptr->next = new_data;
        new_data->next = NULL;
        ptr = ptr->next;
    }
    *outputList = head->next;
}

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SortList(ListNode* head)
{
    if (!head) return;

    bool swapped;
    ListNode* ptr1;
    ListNode* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->val > ptr1->next->val) {
                Swap(&ptr1->val, &ptr1->next->val);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoLists(struct ListNode* list1, struct ListNode* list2) {
    ListNode* ptr;
    ListNode* head;
    ListNode* new_data;
    head = (ListNode*)malloc(sizeof(ListNode));

    head->next = NULL;
    ptr = head;

    while (list1 || list2) {
        int value1 = (list1 != NULL) ? list1->val : 0;
        int value2 = (list2 != NULL) ? list2->val : 0;

        new_data = (ListNode*)malloc(sizeof(ListNode));
        new_data->val = value1+ value2;
        ptr->next = new_data;
        new_data->next = NULL;
        ptr = ptr->next;
		list1 = (list1 != NULL) ? list1->next:list1;
		list2 = (list2 != NULL) ? list2->next:list2;
    }

    return head->next;
}



// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
