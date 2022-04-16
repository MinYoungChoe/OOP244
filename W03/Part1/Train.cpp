#include <iostream>
#include <string.h>
#include "Train.h"

using namespace std;
namespace sdds{
void Train::set(const char* newTrainName, int newNumOfPeople, double newSpeed){
    if((newTrainName != nullptr && newTrainName[0] != '\0')
       &&(newNumOfPeople > 0 ) && (newSpeed > 0 && newSpeed < MAX_SPEED)){
        strncpy(TrainName, newTrainName,MAX_NAME_LEN);
        numOfPeople = newNumOfPeople;
        speed = newSpeed;
    }
    else{

        TrainName[0] = '\0';
        numOfPeople = 0;
        speed = 0;
    }
}

int Train::getNumberOfPeople() const{
    return numOfPeople;
}

const char* Train::getName() const{
    return TrainName;
}

double Train::getSpeed() const{
    return speed;
}

bool Train::isSafeEmpty() const{
    bool isEmpty = false;
    
    if(TrainName[0] == '\0' && numOfPeople == 0 && speed == 0){
        isEmpty = true;
    }
    else{
        isEmpty = false;
    }
    return isEmpty;
}

void Train::display() const{
    
    if(isSafeEmpty() == 1){
        
        cout << "Safe Empty State!" <<endl;
        
    }
    else{
        cout << "NAME OF THE TRAIN : " << TrainName << endl;
        cout << "NUMBER OF PEOPLE  : " << numOfPeople << endl;
        cout << "SPEED             : ";
        cout << std::fixed;
        cout.precision(2);
        cout << speed << " km/h" << endl;
        
    }
}

};
