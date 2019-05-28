#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "utils/utils.h"

#include "utils/collections.h"

#include "structs.h"
#include "files.h"
#include "solver.h"

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

void main(int argc, char** argv)
{
#if 0
	// Find memory leak, set to 1 to use
	_CrtSetBreakAlloc(99);
#endif

	GeneralTreeNode* pHistoricalTree;
	char* pInputFileName, * pOutputFileName;
	unsigned char* pMatrix;

	// Validate arguments
	if (argc != 3)
	{
		printf("Usage: %s input_file output_file", argv[0]);
		return;
	}

	// Save arguments
	pInputFileName = argv[1];
	pOutputFileName = argv[2];

	// Create and init historical tree
	pHistoricalTree = CreateGeneralTreeNode();
	pHistoricalTree->pData = CreateAction();

	pMatrix = ReadFile(pInputFileName);

	if (Solve(pMatrix, pHistoricalTree))
	{

	}
	else
	{
		PrintInfo("No solution found!");
	}

	ExportFile(pOutputFileName, pMatrix);

	FreeGeneralTree(pHistoricalTree, FreeAction);

	free(pMatrix);

	_CrtDumpMemoryLeaks();
}