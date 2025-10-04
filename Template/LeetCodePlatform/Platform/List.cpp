#include "List.h"

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