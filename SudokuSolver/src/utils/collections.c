#include "collections.h"

#include <stdio.h>

#pragma region Lists

List* CreateList()
{
	List* list = (List*)malloc(sizeof(List));

	if (!list) return NULL;

	list->head = list->tail = NULL;
	list->count = 0;
}

ListNode* CreateListNode()
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	if (!node) return NULL;

	node->next = NULL;
	node->data = NULL;

	return node;
}

void FreeList(List* list, void (*FreeData)(void*))
{
	if (!list) return;
	if (!list->head) return;

	for (ListNode* node = list->head, *next = node->next; node; node = next, next = node->next)
	{
		FreeData(node->data);
		free(node);
	}

	free(list);
}

void ListAddTail(List* list, void* data)
{
	if (!list) return;

	ListNode* node;

	if (!list->head)
	{
		ListAddHead(list, data);
		return;
	}

	node = CreateListNode();
	node->data = data;

	list->tail->next = node;
	list->tail = node;
	list->count++;
}

void ListAddHead(List* list, void* data)
{
	if (!list) return;

	ListNode* node;

	node = CreateListNode();
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

void FreeGeneralTree(TreeNode* root, void (*FreeData)(void*))
{
	if (!root) return;

	// Recursively free child nodes
	FreeList(root->childs, FreeGeneralTree);

	FreeData(root->data);

	free(root);
}

#pragma endregion General Trees