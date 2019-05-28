#ifndef FILES_H_
#define FILES_H_

#define _CRT_SECURE_NO_WARNINGS

#define FM_R "r"
#define FM_W "w"
#define FM_A "a"

#define FM_RP "r+"
#define FM_WP "w+"
#define FM_AP "a+"

#define FM_RB "rb"
#define FM_WB "wb"
#define FM_AB "ab"

#define FM_RBP "rb+"
#define FM_WBP "wb+"
#define FM_ABP "ab+"

#include <stdio.h>
#include <stdlib.h>

#include "utils/utils.h"
#include "utils/collections.h"

#include "structs.h"

unsigned char* ReadFile(char* pFileName);

void ExportFile(char* pFileName, unsigned char* pMatrix);

#endif // !FILES_H_