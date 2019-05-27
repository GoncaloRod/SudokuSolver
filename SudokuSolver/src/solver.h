#ifndef SOLVER_H_
#define SOLVER_H_

void Solve(unsigned char* pMatrix, GeneralTreeNode* pHistoricalTree);

void LineRule(unsigned char* pMatrix, List* pPossibilities, Vector2I position);

#endif // !SOLVER_H_
