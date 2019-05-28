#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdlib.h>

#include "utils/collections.h"

#include "structs.h"

int Solve(unsigned char* pMatrix, GeneralTreeNode* pHistoricalTree);

void LineRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position);

void ColumnRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position);

void SquareRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position);

#endif // !SOLVER_H_
