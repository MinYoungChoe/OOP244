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

bool Train::isSafeEmpty()const{
    bool is_true = false;
    
    if(TrainName[0] == '\0' && numOfPeople == 0 && speed == 0){
        is_true = true;
    }
    else{
        is_true = false;
    }
    return is_true;
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

bool Train::loadPeople(int newNumOfPeople){
    
    bool is_empty = false;
    
    if(newNumOfPeople < 0){
        
        if((numOfPeople +
            newNumOfPeople) < 0){
            numOfPeople = 0;
            is_empty = false;
        }
        else{
            numOfPeople = numOfPeople +
            newNumOfPeople;
            is_empty = true;
        }
    }
    
    else if(newNumOfPeople > 0){
        
        if((numOfPeople + newNumOfPeople) >= MAX_PEOPLE){
            numOfPeople = MAX_PEOPLE;
            is_empty = false;
        }
        
        else{
            numOfPeople = numOfPeople + newNumOfPeople;
            is_empty = true;
        }
    }
    return is_empty;
}

bool Train::changeSpeed(int newSpeed){
    bool is_empty = false;
    
    if(newSpeed < 0){
        
        if((speed + newSpeed) < 0){
            speed = 0;
            is_empty = false;
        }
        else{
            speed = speed + newSpeed;
            is_empty = true;
        }
    }
    else if(newSpeed > 0){
        if((speed + newSpeed) > MAX_SPEED){
            speed = MAX_SPEED;
            is_empty = false;
        }
        else{
            speed = speed + newSpeed;
            is_empty = true;
        }
    }
    return is_empty;
    
}

int transfer(Train &first, Train &second){
    int numOfPeopleOfFirst = first.getNumberOfPeople();
    
    int numOfPeopleOfSecond = second.getNumberOfPeople();
    
    int spaceOfFirst = MAX_PEOPLE - numOfPeopleOfFirst;
    
    int sendingToFirst = spaceOfFirst;
    
    if(numOfPeopleOfFirst > 0 && numOfPeopleOfSecond > 0){
        
        first.loadPeople(+sendingToFirst);
        second.loadPeople(-sendingToFirst);
        
    }
    else{
        sendingToFirst = -1;
    }
    return sendingToFirst;
    
}

}
