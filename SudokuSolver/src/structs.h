#ifndef STRUCTS_H_
#define STRUCTS_H_

#pragma region Vector2I

typedef struct _vector2I
{
	int x, y;
} Vector2I;

Vector2I* CreateVector2I();

void FreeVector2I(void* pVector);

#pragma endregion

#pragma region Action

typedef struct _action
{
	Vector2I position;
	int number;
} Action;

Action* CreateAction();

void FreeAction(void* pAction);

#pragma endregion Action

#endif // !STRUCTS_H_