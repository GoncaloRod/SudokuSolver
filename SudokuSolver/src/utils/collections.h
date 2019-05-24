#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_

#pragma region Lists

typedef struct _listNode
{
	struct _listNode* next;
	void* data;
} ListNode;

typedef struct _list
{
	ListNode* head, * tail;
	int count;
} List;

List* CreateList();

ListNode* CreateListNode();

void FreeList(List* list, void (*FreeData)(void*));

void ListAddTail(List* list, void* data);

void ListAddHead(List* list, void* data);

#pragma endregion Lists

#pragma region General Trees

typedef struct _treeNode
{
	List* childs;
	void* data;
} TreeNode;

TreeNode* CreateTreeNode();

void FreeGeneralTree(TreeNode* root, void (*FreeData)(void*));

#pragma endregion General Trees

#endif // !COLLECTIONS_H_