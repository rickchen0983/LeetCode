// MergeTwoSortedLists.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;
};

void ArrayToList(int* array, int dataLength, ListNode** outputList);
ListNode* addTwoLists(struct ListNode* list1, struct ListNode* list2);

int main()
{
    int array1[7] = { 9,9,9,9,9,9,9 };
    int dataLength1 = sizeof(array1) / sizeof(array1[0]);
    int* ptrArray1 = array1;
    int array2[4] = { 9,9,9,9 };
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
	int carry = 0;

    while (list1 || list2 || carry != 0) {
        int value1 = (list1 != NULL) ? list1->val : 0;
        int value2 = (list2 != NULL) ? list2->val : 0;

        new_data = (ListNode*)malloc(sizeof(ListNode));
        new_data->val = (value1+ value2 + carry)%10;
		carry = (value1 + value2 + carry) / 10;
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
