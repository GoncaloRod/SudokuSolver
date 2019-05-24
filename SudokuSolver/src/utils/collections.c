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

#pragma endregion Lists

#pragma region General Trees

TreeNode* CreateTreeNode()
{
	TreeNode* pNode = CreateTreeNode();

	pNode->pChilds = NULL;
	pNode->pData = NULL;

	return pNode;
}

void FreeGeneralTree(TreeNode* pRoot, void (*FreeData)(void*))
{
	if (!pRoot) return;

	// Recursively free child nodes
	FreeList(pRoot->pChilds, FreeGeneralTree);

	FreeData(pRoot->pData);

	free(pRoot);
}

#pragma endregion General Trees