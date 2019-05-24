#include "files.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/utils.h"
#include "utils/collections.h"

#include "structs.h"

void ReadFile(char* fileName, unsigned char* matrix)
{
	FILE* file;
	int number = 0;
	
	// Open file
	file = fopen(fileName, FM_R);

	if (!file)
	{
		PrintError("Failed to open file!");
		exit(EXIT_FAILURE);
	}

	// Allocate matrix
	matrix = (unsigned char*)malloc(sizeof(unsigned char) * (9 * 9));

	if (!matrix)
	{
		PrintError("Failed to allocate memory!");

		fclose(file);

		exit(EXIT_FAILURE);
	}

	// Read file
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (fscanf(file, "%d", &number) != 1)
			{
				PrintError("Invalid file format! Missing numbers!");

				fclose(file);
				free(matrix);

				exit(EXIT_FAILURE);
			}

			matrix[i * 9 + j] = (unsigned char)number;
		}
	}

	fclose(file);
}