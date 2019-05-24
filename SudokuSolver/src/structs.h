#ifndef STRUCTS_H_
#define STRUCTS_H_

#pragma region Vector2I

typedef struct _vector2I
{
	int x, y;
} Vector2I;

Vector2I* CreateVector2I();

void FreeVector2I(Vector2I* pVector);

#pragma endregion


#endif // !STRUCTS_H_
