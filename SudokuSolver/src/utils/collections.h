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

List* CreateLinkedList();

ListNode* CreateLinkedListNode();

void FreeLinkedList(List* list, void (*FreeData)(void*));

void LinkedListAddTail(List* list, void* data);

void LinkedListAddHead(List* list, void* data);

#pragma endregion Lists

#pragma region General Trees

typedef struct _treeNode
{
	List* childs;
	void* data;
} TreeNode;

TreeNode* CreateTreeNode();

#pragma endregion General Trees

#endif // !COLLECTIONS_H_