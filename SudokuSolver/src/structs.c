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

void FreeVector2I(void* pVector)
{
	if (!pVector) return;

	free((Vector2I*)pVector);
}

#pragma endregion Vector2I

#pragma region Action

Action* CreateAction()
{
	Action* pAction = (Action*)malloc(sizeof(Action));

	if (!pAction) return NULL;

	pAction->number = 0;
	pAction->position.x = pAction->position.y = 0;

	return pAction;
}

void FreeAction(void* pAction)
{
	if (!pAction) return;

	free((Action*)pAction);
}

#pragma endregion Action