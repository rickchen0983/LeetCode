#include "List.h"
#include <stdlib.h>
#include <stdio.h>

struct ListNode* createNode(int value)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->val = value;
	newNode->next = NULL;
	return newNode;
}

void appendNode(struct ListNode** head, int value)
{
	struct ListNode* newNode = createNode(value);
	if (*head == NULL) {
		*head = newNode;
	}
	else {
		struct ListNode* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

void searchNode(struct ListNode* head, int value)
{
	struct ListNode* current = head;
	while (current != NULL) {
		if (current->val == value) {
			printf("Found: %d\n", value);
			return;
		}
		current = current->next;
	}
	printf("Not Found: %d\n", value);
}

void deleteNode(struct ListNode** head, int value)
{
	if (*head == NULL) return;
	if ((*head)->val == value) {
		struct ListNode* temp = *head;
		*head = (*head)->next;
		free(temp);
		return;
	}
	struct ListNode* current = *head;
	while (current->next != NULL && current->next->val != value) {
		current = current->next;
	}
	if (current->next != NULL) {
		struct ListNode* temp = current->next;
		current->next = current->next->next;
		free(temp);
	}
}

void ArrayToList(int* array, int dataLength, struct ListNode** outputList)
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