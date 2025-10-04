// MergeTwoSortedLists.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;
};

void ArrayToList(int* array, int dataLength, ListNode** outputList);
struct ListNode* swapPairs(struct ListNode* head);
struct ListNode* createNode(int value);
void appendNode(ListNode** head, int value);
void searchNode(ListNode* head, int value);
void deleteNode(ListNode** head, int value);

int main()
{
    int array1[4] = { 1,2,3,4 };
    int dataLength1 = sizeof(array1) / sizeof(array1[0]);
    int* ptrArray1 = array1;
    ListNode* list1 = NULL;
    ArrayToList(ptrArray1, dataLength1, &list1);
    swapPairs(list1);
}

struct ListNode* createNode(int value)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->val = value;
	newNode->next = NULL;
	return newNode;
}

void appendNode(ListNode** head, int value)
{
	ListNode* newNode = createNode(value);
	if (*head == NULL) {
		*head = newNode;
	}
	else {
		ListNode* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

void searchNode(ListNode* head, int value)
{
	ListNode* current = head;
	while (current != NULL) {
		if (current->val == value) {
			std::cout << "Found: " << value << std::endl;
			return;
		}
		current = current->next;
	}
	std::cout << "Not Found: " << value << std::endl;
}

void deleteNode(ListNode** head, int value)
{
	if (*head == NULL) return;
	if ((*head)->val == value) {
		ListNode* temp = *head;
		*head = (*head)->next;
		free(temp);
		return;
	}
	ListNode* current = *head;
	while (current->next != NULL && current->next->val != value) {
		current = current->next;
	}
	if (current->next != NULL) {
		ListNode* temp = current->next;
		current->next = current->next->next;
		free(temp);
	}
}

void ArrayToList(int* array, int dataLength, ListNode** outputList)
{
	for (int i = 0; i < dataLength; i++)
	{
		appendNode(outputList, array[i]);
	}
}

struct ListNode* swapPairs(struct ListNode* head)
{
	struct ListNode dummy;
	dummy.next = head;
	struct ListNode* prev = &dummy;

	while (prev->next && prev->next->next) {
		struct ListNode* first = prev->next;
		struct ListNode* second = first->next;

		first->next = second->next;
		second->next = first;
		prev->next = second;

		prev = first;
	}

	return dummy.next;
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
