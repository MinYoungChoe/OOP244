#ifndef SDDS_cStrTools_H
#define SDDS_cStrTools_H
#include <stdio.h>

namespace sdds {
char toLower(char ch);
int strCmp(const char* s1, const char* s2);
int strnCmp(const char* s1, const char* s2, int len);
void strCpy(char* des, const char* src);
int strLen(const char* str);
const char* strStr(const char* str, const char* find);
int isAlpha(char ch);
int isSpace(char ch);
void trim(char word[]);
void toLowerCaseAndCopy(char des[], const char source[]);

}



#endif /* SDDS_cStrTools_H */
