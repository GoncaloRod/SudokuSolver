#include <stdio.h>
#include <stdlib.h>

#include "utils/utils.h"
#include "utils/collections.h"

#include "structs.h"
#include "files.h"
#include "solver.h"

void main(int argc, char** argv)
{
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

	Solve(pMatrix, pHistoricalTree);

	ExportFile(pOutputFileName, pMatrix);

	free(pMatrix);
}