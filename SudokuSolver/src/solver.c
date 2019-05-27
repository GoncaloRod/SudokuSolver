#include "solver.h"

#include "utils/collections.h"

#include "structs.h"

void Solve(unsigned char* pMatrix, GeneralTreeNode* pHistoricalTree)
{
	if (!pMatrix) return;

	Vector2I position;
	List* pPossibilities;

	// Init possibilities list
	pPossibilities = CreateList();

	for (int i = 1; i <= 9; ++i)
	{
		int* pNumber = (int*)malloc(sizeof(int));

		*pNumber = i;

		ListAddTail(pPossibilities, (void*)pNumber);
	}

	// Find available position
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (pMatrix[i * 9 + j] != 0)
			{
				position.x = j;
				position.y = i;

				break;
			}
		}
	}

	// Apply rules

	LineRule(pMatrix, pPossibilities, position);

	// TODO: Column rule

	// TODO: Square rule
}

void LineRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position)
{
	if (!pMatrix) return;
	if (!pPossibilities) return;
	if (!pPossibilities->pHead) return;

	// TODO: This function
}