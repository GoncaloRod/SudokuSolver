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
}

void LineRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position)
{
	if (!pMatrix) return;
	if (!pPossibilities) return;
	if (!pPossibilities->pHead) return;

	List* pExisting = CreateList();
	int* pNumber;

	for (int i = 0; i < 9; ++i)
	{
		if (pMatrix[position.y * 9 + i] != 0)
		{
			pNumber = (int*)malloc(sizeof(int));

			if (!pNumber) return;

			*pNumber = pMatrix[position.y * 9 + i];

			ListAddTail(pExisting, (void*)pNumber);
		}
	}

	// TODO: Remove

	FreeList(pExisting, free);
}

void ColumnRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position)
{
	// TODO: This function
}

void SquareRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position)
{
	// TODO: This function
}
