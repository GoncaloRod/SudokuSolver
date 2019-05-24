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

void ReadFile(char* fileName, unsigned char* matrix);

#endif // !FILES_H_