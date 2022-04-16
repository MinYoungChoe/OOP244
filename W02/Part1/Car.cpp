#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Car.h"
#include "cStrTools.h"
using namespace std;
namespace sdds {


Car* theCarPointer;
int allocationSize;
int carArraySize;
int numberOfCars;

void VBPLE_Title(){
    cout << "Vehicle Border Passing Log Entry" << endl;
    cout << "Enter the data in the following format:" << endl;
    cout << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl;
    cout << "Exit the program by entering the following:" << endl;
    cout << "X,<ENTER>" << endl;
}
//
void initialize(int allocSize){
    numberOfCars = 0;
    carArraySize = allocSize;
    allocationSize = allocSize;
    theCarPointer = new Car[allocationSize];
}

void deallocate(Car& C){
    delete [] C.makeAndModel;
    C.makeAndModel = nullptr;
    
}

bool read(Car& C){
    bool boolean = false;
    char tempMakeAndModel[61];
    tempMakeAndModel[0] = '\0';
    read(tempMakeAndModel, 60, ',');
    int len = strlen(tempMakeAndModel);

    if(strcmp("X",tempMakeAndModel)!= 0){
        boolean = true;
        C.makeAndModel = new char[len+1];
        strcpy(C.makeAndModel, tempMakeAndModel);
        read(C.plate, 8, ',');
        cin >> C.time;
    }
    
    return boolean;
}
void print(const Car& C){
    
    cout << C.time <<": " << C.makeAndModel << "," << C.plate <<endl;
}

void record(const Car& C){
    
    if(numberOfCars == carArraySize){
        carArraySize += allocationSize;
        Car* temp = new Car[carArraySize];
        for(int i = 0; i < numberOfCars; i++){
            temp[i] = theCarPointer[i];
        }
        delete [] theCarPointer;
        theCarPointer = temp;
    }
    theCarPointer[numberOfCars] = C;
    numberOfCars++;
    
}
void endOfDay(){
    
    for(int i = 0; i < numberOfCars; i++){
    
        print(theCarPointer[i]);
        deallocate(theCarPointer[i]);
    }
    
    delete [] theCarPointer;
    theCarPointer = nullptr;
}
}



