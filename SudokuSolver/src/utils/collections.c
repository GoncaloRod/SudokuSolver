#include "collections.h"

#include <stdio.h>

#pragma region Lists

List* CreateLinkedList()
{
	List* list = (List*)malloc(sizeof(List));

	if (!list) return NULL;

	list->head = list->tail = NULL;
	list->count = 0;
}

ListNode* CreateLinkedListNode()
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	if (!node) return NULL;

	node->next = NULL;
	node->data = NULL;

	return node;
}

void FreeLinkedList(List* list, void (*FreeData)(void*))
{
	if (!list) return;
	if (!list->head) return;

	for (ListNode* node = list->head, *next = node->next; node; node = next, next = node->next)
	{
		free(node->data);
		free(node);
	}

	free(list);
}

void LinkedListAddTail(List* list, void* data)
{
	if (!list) return;

	ListNode* node;

	if (!list->head)
	{
		LinkedListAddHead(list, data);
		return;
	}

	node = CreateLinkedListNode();
	node->data = data;

	list->tail->next = node;
	list->tail = node;
	list->count++;
}

void LinkedListAddHead(List* list, void* data)
{
	if (!list) return;

	ListNode* node;

	node = CreateLinkedListNode();
	node->data = data;

	node->next = list->head;
	list->head = node;

	if (!list->tail) list->tail = node;

	list->count++;
}

#pragma endregion Lists

#pragma region General Trees

TreeNode* CreateTreeNode()
{
	TreeNode* node = CreateTreeNode();

	node->childs = NULL;
	node->data = NULL;

	return node;
}

#pragma endregion General Trees