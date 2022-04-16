#define _CRT_SECURE_NO_WARNINGS
#include "Word.h"
#include <iostream>
#include <iomanip>

using namespace sdds;
using namespace std;
int main_WordStat() {
   char filename[256];
   programTitle();
   cout << "Enter filename: ";
   cin >> filename;
   wordStats(filename);
   return 0;
}
