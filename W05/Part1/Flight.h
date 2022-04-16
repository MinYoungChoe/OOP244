#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

using namespace std;

namespace sdds {

const int Boen747Capacity = 388;
const int FuelTankCapacity = 238840;

class Flight {
    
    int m_passengers = 0;
    double m_fuel = 0;
    char m_title[16];
    void emptyPlane();
    
public:
    Flight();
    Flight(int passengers, double fuel, const char* title);
    std::ostream& display()const;
    operator bool() const;
    operator int() const;
    operator double() const;
    operator const char*() const;
    bool operator ~() const;
    Flight& operator =(Flight& flight);
    Flight& operator =(int newNumberOfPassengers);
    Flight& operator =(double newAmountOfFuel);
    Flight& operator +=(double newAmountOfFuel);
    Flight& operator +=(int newNumberOfPassengers);
    Flight& operator -=(double newAmountOfFuel);
    Flight& operator -=(int newNumberOfPassengers);
    Flight& operator <<(Flight& flight);
    Flight& operator >>(Flight &flight);
    
};

int operator +(const Flight& left, const Flight& right);
int& operator +=(int& left, const Flight& right);

}
#endif // SDDS_FLIGHT_H
