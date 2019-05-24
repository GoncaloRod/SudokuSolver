#include "structs.h"

#include <stdio.h>
#include <stdlib.h>

#pragma region Vector2I

Vector2I* CreateVector2I()
{
	Vector2I* pVector = (Vector2I*)malloc(sizeof(Vector2I));

	if (!pVector) return NULL;

	pVector->x = pVector->y = 0;

	return pVector;
}

void FreeVector2I(Vector2I* pVector)
{
	if (!pVector) return;

	free(pVector);
}

#pragma endregion