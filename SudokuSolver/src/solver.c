#include "solver.h"

void Solve(unsigned char* pMatrix, GeneralTreeNode* pHistoricalTree)
{
	if (!pMatrix) return;

	Vector2I position;
	List* pPossibilities;
	int* pNumber;
	int found = 0;

	// Init possibilities list
	pPossibilities = CreateList();

	for (int i = 1; i <= 9; ++i)
	{
		pNumber = (int*)malloc(sizeof(int));

		if (!pNumber) return;

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

	// Apply rules
	LineRule(pMatrix, pPossibilities, position);

	ColumnRule(pMatrix, pPossibilities, position);

	SquareRule(pMatrix, pPossibilities, position);

	// TODO: Create possibility nodes

	// Free possibilities list
	FreeList(pPossibilities, free);
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

	List* pExisting = CreateList();
	int* pNumber;

	// Find number in column
	for (int i = 0; i < 9; ++i)
	{
		if (pMatrix[i * 9 + position.x] != 0)
		{
			pNumber = (int*)malloc(sizeof(int));

			if (!pNumber) return;

			*pNumber = pMatrix[i * 9 + position.x];

			ListAddTail(pExisting, (void*)pNumber);
		}
	}

	// TODO: Remove existing from list

	FreeList(pExisting, free);
}

void SquareRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position)
{
	if (!pMatrix) return;
	if (!pPossibilities) return;
	if (!pPossibilities->pHead) return;

	List* pExisting = CreateList();
	int* pNumber;

	// Find numbers in square
	for (int i = position.y - (position.y % 3); i < position.y - (position.y % 3) + 3; ++i)
	{
		for (int j = position.x - (position.x % 3); j < position.x - (position.x % 3) + 3; ++j)
		{
			if (pMatrix[i * 9 + j] != 0)
			{
				pNumber = (int*)malloc(sizeof(int));

				if (!pNumber) return;

				*pNumber = pMatrix[i * 9 + j];

				ListAddTail(pExisting, pNumber);
			}
		}
	}

	// TODO: Remove existing from list

	FreeList(pExisting, free);
}
