#ifndef SDDS_Train_h
#define SDDS_Train_h
#include <string.h>
#include <iostream>

const int MAX_NAME_LEN = 20;
const int MAX_PEOPLE = 1000;
const double MAX_SPEED = 320;

namespace sdds {
class Train{
private:
    char TrainName[MAX_NAME_LEN+1];
    int numOfPeople;
    double speed;
public:
    void set(const char* newTrainName, int newNumOfPeople, double newSpeed);
    int getNumberOfPeople() const;
    const char* getName() const;
    double getSpeed() const;
    bool isSafeEmpty() const;
    void display() const;
};
}

#endif /* SDDS_Train_h */
