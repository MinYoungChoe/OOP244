#ifndef SDDS_DNA_hpp
#define SDDS_DNA_hpp
#include <stdio.h>

struct Dna{
    int sixDigits;
    char* strands;
};

namespace sdds{
bool beginSearch(const char *filename);
bool read(const char* subDNA);
void sort();
void displayMatches();
void deallocate();
void endSearch();
int NumberOfMatches(const char* DnaOfentry);
}






#endif /* SDDS_DNA_hpp */
