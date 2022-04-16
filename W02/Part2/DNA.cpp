#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "cStrTools.h"
#include "DNA.h"
using namespace std;
namespace sdds{

int allocationSize;
int dnaArraySize;
int numberOfDna;
int currentLocation;
FILE *fp = NULL;
Dna* dnaPointer;
Dna tempOfDna;
int i;
int idx;

bool beginSearch(const char *filename){
    bool boolean = false;
    allocationSize = 0;
    dnaArraySize = 0;
    numberOfDna = 0;
    currentLocation = 0;
    i = 0;
    idx = 0;
    
    
    fp=fopen(filename, "r");
    if (fp != NULL){
        boolean = true;
    }
    
    else{
        boolean = false;
    }
    cout << "DNA search program" << endl;
    return boolean;
}

int NumberOfMatches(const char* dnaEntry){
    
    char dna[1001];
    int sixdigit;
    int num = 0;
    while(fscanf(fp, "%d, %s/n", &sixdigit, dna)!= EOF){
        if((strStr(dna, dnaEntry) != nullptr)){

            num++;
        }
        else{
            ;
        }
    }
    rewind(fp);
    return num;
}

bool read(const char* subDNA){
    bool boolean = false;
    int tempSixdigit;
    char tempDna[1001];
    tempDna[0] = '\0';
    
    dnaArraySize = NumberOfMatches(subDNA);
    
    if(dnaArraySize > 0){
        dnaPointer = new Dna[dnaArraySize];
        while(fscanf(fp, "%d, %s\n", &tempSixdigit, tempDna)!= EOF){
            if((strStr(tempDna, subDNA) != nullptr)){
                dnaPointer[idx].strands = new char[strLen(tempDna)+1];
                strCpy(dnaPointer[idx].strands, tempDna);
                dnaPointer[idx].sixDigits = tempSixdigit;
                //                printf("hello\n");
                idx++;
                boolean = true;
            }
        }
        
    }
    rewind(fp);
    return boolean;
    
}

void sort(){
    int i, j;
    Dna* a = dnaPointer;
    Dna temp;
    
    for (i = dnaArraySize - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (a[j].sixDigits > a[j+1].sixDigits) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
}
void displayMatches(){
    cout << dnaArraySize << " matches found:" << endl;
    for(i = 0; i < dnaArraySize; i++){
        cout << i+1 << ") ";
        cout << dnaPointer[i].sixDigits << ":" << endl;
        cout << dnaPointer[i].strands << endl;
        cout << "======================================================================" << endl;
    }
    
}
void deallocate(){

    for(i = 0; i < idx; i++){
        delete [] dnaPointer[i].strands;
        dnaPointer[i].strands = nullptr;
    }
    
    delete [] dnaPointer;
    dnaPointer = nullptr;
    
    
    
}
void endSearch(){
    cout << "DNA Search Program Closed." << endl;
    fclose(fp);
    
}
}

