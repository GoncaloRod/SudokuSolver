#include "collections.h"

#include <stdio.h>
#include <stdlib.h>

#pragma region Lists

List* CreateList()
{
	List* pList = (List*)malloc(sizeof(List));

	if (!pList) return NULL;

	pList->pHead = pList->pTail = NULL;
	pList->count = 0;

	return pList;
}

ListNode* CreateListNode()
{
	ListNode* pNode = (ListNode*)malloc(sizeof(ListNode));

	if (!pNode) return NULL;

	pNode->pNext = NULL;
	pNode->pData = NULL;

	return pNode;
}

void FreeList(List* pList, void (*FreeData)(void*))
{
	if (!pList) return;
	if (!pList->pHead) return;

	for (ListNode* node = pList->pHead, *next = node->pNext; node; node = next, next = node->pNext)
	{
		FreeData(node->pData);
		free(node);
	}

	free(pList);
}

void ListAddTail(List* pList, void* pData)
{
	if (!pList) return;

	ListNode* pNode;

	if (!pList->pHead)
	{
		ListAddHead(pList, pData);
		return;
	}

	pNode = CreateListNode();
	pNode->pData = pData;

	pList->pTail->pNext = pNode;
	pList->pTail = pNode;
	pList->count++;
}

void ListAddHead(List* pList, void* pData)
{
	if (!pList) return;

	ListNode* pNode;

	pNode = CreateListNode();
	pNode->pData = pData;

	pNode->pNext = pList->pHead;
	pList->pHead = pNode;

	if (!pList->pTail) pList->pTail = pNode;

	pList->count++;
}

void ListRemoveByIndex(List* pList, int index, void (*FreeData)(void*))
{
	if (!pList) return;
	if (!pList->pHead) return;
	if (pList->count - 1 < index) return;

	ListNode* pNode = pList->pHead, * pToRemove;

	for (int i = 0; i < index - 1; ++i, pNode = pNode->pNext);

	pToRemove = pNode->pNext;
	pNode->pNext = pToRemove->pNext;

	FreeData(pToRemove->pData);
	free(pToRemove);
}

void ListRemoveFromList(List* pList, List* pToRemove, void (*FreeData)(void*))
{
	if (!pList) return;
	if (!pList->pHead) return;
	if (!pToRemove) return;
	if (!pToRemove->pHead) return;

	// TODO: This function
}

#pragma endregion Lists

#pragma region General Trees

GeneralTreeNode* CreateGeneralTreeNode()
{
	GeneralTreeNode* pNode = CreateGeneralTreeNode();

	pNode->pChilds = NULL;
	pNode->pData = NULL;

	return pNode;
}

void FreeGeneralTree(GeneralTreeNode* pRoot, void (*FreeData)(void*))
{
	if (!pRoot) return;

	// Recursively free child nodes
	FreeList(pRoot->pChilds, FreeGeneralTree);

	FreeData(pRoot->pData);

	free(pRoot);
}

#pragma endregion General Trees