#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_

#pragma region Lists

typedef struct _listNode
{
	struct _listNode* pNext;
	void* pData;
} ListNode;

typedef struct _list
{
	ListNode* pHead, * pTail;
	int count;
} List;

List* CreateList();

ListNode* CreateListNode();

void FreeList(List* pList, void (*FreeData)(void*));

void ListAddTail(List* pList, void* pData);

void ListAddHead(List* pList, void* pData);

#pragma endregion Lists

#pragma region General Trees

typedef struct _generalTreeNode
{
	List* pChilds;
	void* pData;
} GeneralTreeNode;

GeneralTreeNode* CreateGeneralTreeNode();

void FreeGeneralTree(GeneralTreeNode* pRoot, void (*FreeData)(void*));

#pragma endregion General Trees

#endif // !COLLECTIONS_H_