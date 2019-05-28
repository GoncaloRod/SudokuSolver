#include "files.h"

unsigned char* ReadFile(char* pFileName)
{
	FILE* pFile;
	int number = 0;
	unsigned char* pMatrix;
	
	// Open file
	pFile = fopen(pFileName, FM_R);

	if (!pFile)
	{
		PrintError("Failed to open input file!");
		exit(EXIT_FAILURE);
	}

	// Allocate matrix
	pMatrix = (unsigned char*)malloc(sizeof(unsigned char) * (9 * 9));

	if (!pMatrix)
	{
		PrintError("Failed to allocate memory!");

		fclose(pFile);

		exit(EXIT_FAILURE);
	}

	// Read file
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (fscanf(pFile, "%d", &number) != 1)
			{
				PrintError("Invalid file format! Missing numbers!");

				fclose(pFile);
				free(pMatrix);

				exit(EXIT_FAILURE);
			}

			pMatrix[i * 9 + j] = (unsigned char)number;
		}
	}

	fclose(pFile);

	return pMatrix;
}

void ExportFile(char* pFileName, unsigned char* pMatrix)
{
	if (!pMatrix) return;

	FILE* pFile;

	// Open file
	pFile = fopen(pFileName, FM_W);

	if (!pFile)
	{
		PrintError("Failed to open output file!");
		exit(EXIT_FAILURE);
	}

	// Write matrix to file
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			fprintf(pFile, "%d ", pMatrix[i * 9 + j]);
		}

		fprintf(pFile, "\n");
	}
}
