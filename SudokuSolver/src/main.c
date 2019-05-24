#include <stdio.h>
#include <stdlib.h>

#include "utils/utils.h"
#include "utils/collections.h"

#include "structs.h"
#include "files.h"

void main(int argc, char** argv)
{
	char* inputFileName, * outputFileName;
	unsigned char* matrix = NULL;

	if (argc != 3)
	{
		printf("Usage: %s input_file output_file", argv[0]);
		return;
	}

	inputFileName = argv[1];
	outputFileName = argv[2];

	ReadFile(inputFileName, matrix);

	// TODO: Solve

	free(matrix);
}