#include "solver.h"

int Solve(unsigned char* pMatrix, GeneralTreeNode* pHistoricalTree)
{
	if (!pMatrix) return;

	Vector2I position;
	List* pPossibilities;
	GeneralTreeNode* pNewTreeNode;
	Action* pNewAction;
	int* pNumber;
	int found = 0;

	// Init position
	position.x = position.y = -1;

	// Init possibilities list
	pPossibilities = CreateList();

	for (int i = 1; i <= 9; ++i)
	{
		pNumber = (int*)malloc(sizeof(int));

		if (!pNumber) exit(EXIT_FAILURE);

		*pNumber = i;

		ListAddTail(pPossibilities, (void*)pNumber);
	}

	// Find available position
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (pMatrix[i * 9 + j] == 0)
			{
				position.x = j;
				position.y = i;

				found = 1;

				break;
			}
		}

		if (found) break;
	}

	// No available spaces means the Sudoku is solved
	if (position.x == -1 && position.y == -1)
	{
		return 1;
	}

	// Apply rules
	LineRule(pMatrix, pPossibilities, position);

	ColumnRule(pMatrix, pPossibilities, position);

	SquareRule(pMatrix, pPossibilities, position);

	// Create possibility nodes
	for (ListNode* pNode = pPossibilities->pHead; pNode; pNode = pNode->pNext)
	{
		pNewTreeNode = CreateGeneralTreeNode();
		pNewAction = CreateAction();

		pNewAction->number = *(int*)pNode->pData;
		pNewAction->position.x = position.x;
		pNewAction->position.y = position.y;

		pNewTreeNode->pData = pNewAction;

		ListAddTail(pHistoricalTree->pChilds, (void*)pNewTreeNode);
	}

	// Free possibilities list
	FreeList(pPossibilities, free);

	// Explore possibilities
	for (ListNode* pNode = pHistoricalTree->pChilds->pHead; pNode; pNode = pNode->pNext)
	{
		int num = ((Action*)((GeneralTreeNode*)pNode->pData)->pData)->number;

		pMatrix[position.y * 9 + position.x] = num;

		if (Solve(pMatrix, (GeneralTreeNode*)pNode->pData))
		{
			return 1;
		}
		else
		{
			pMatrix[position.y * 9 + position.x] = 0;
		}
	}

	//FreeGeneralTree(pHistoricalTree, FreeAction);

	return 0;
}

void LineRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position)
{
	if (!pMatrix) return;
	if (!pPossibilities) return;
	if (!pPossibilities->pHead) return;

	int number;

	// Find number in line and remove them
	for (int i = 0; i < 9; ++i)
	{
		number = pMatrix[position.y * 9 + i];

		if (number != 0)
		{
			for (ListNode* pCurrent = pPossibilities->pHead, * pPrevious = NULL; pCurrent; pPrevious = pCurrent, pCurrent = pCurrent->pNext)
			{
				if (*(int*)pCurrent->pData == number)
				{
					if (!pPrevious)
					{
						pPossibilities->pHead = pCurrent->pNext;
					}
					else
					{
						pPrevious->pNext = pCurrent->pNext;
					}
						
					free((int*)pCurrent->pData);
					free(pCurrent);
						
					pPossibilities->count--;

					break;
				}
			}
		}
	}
}

void ColumnRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position)
{
	if (!pMatrix) return;
	if (!pPossibilities) return;
	if (!pPossibilities->pHead) return;

	int number;

	// Find number in column
	for (int i = 0; i < 9; ++i)
	{
		number = pMatrix[i * 9 + position.x];

		if (number != 0)
		{
			for (ListNode* pCurrent = pPossibilities->pHead, *pPrevious = NULL; pCurrent; pPrevious = pCurrent, pCurrent = pCurrent->pNext)
			{
				if (*(int*)pCurrent->pData == number)
				{
					if (!pPrevious)
					{
						pPossibilities->pHead = pCurrent->pNext;
					}
					else
					{
						pPrevious->pNext = pCurrent->pNext;
					}

					free((int*)pCurrent->pData);
					free(pCurrent);

					pPossibilities->count--;

					break;
				}
			}
		}
	}
}

void SquareRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position)
{
	if (!pMatrix) return;
	if (!pPossibilities) return;
	if (!pPossibilities->pHead) return;

	int number;

	// Find numbers in square
	for (int i = position.y - (position.y % 3); i < position.y - (position.y % 3) + 3; ++i)
	{
		for (int j = position.x - (position.x % 3); j < position.x - (position.x % 3) + 3; ++j)
		{
			number = pMatrix[i * 9 + j];

			if (number != 0)
			{
				for (ListNode* pCurrent = pPossibilities->pHead, *pPrevious = NULL; pCurrent; pPrevious = pCurrent, pCurrent = pCurrent->pNext)
				{
					if (*(int*)pCurrent->pData == number)
					{
						if (!pPrevious)
						{
							pPossibilities->pHead = pCurrent->pNext;
						}
						else
						{
							pPrevious->pNext = pCurrent->pNext;
						}

						free((int*)pCurrent->pData);
						free(pCurrent);

						pPossibilities->count--;

						break;
					}
				}
			}
		}
	}
}
