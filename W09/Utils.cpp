#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>
#include "Utils.h"
using namespace std;

namespace sdds {
Utils ut;
void Utils::testMode(bool testmode) {
    m_testMode = testmode;
}
void Utils::getSystemDate(int* year, int* mon, int* day) {
    if (m_testMode) {
        if(day) *day = sdds_testDay;
        if(mon) *mon = sdds_testMon;
        if(year) *year = sdds_testYear;
    }
    else {
        time_t t = std::time(NULL);
        tm lt = *localtime(&t);
        if (day) *day = lt.tm_mday;
        if (mon) *mon = lt.tm_mon + 1;
        if (year) *year = lt.tm_year + 1900;
    }
}
int Utils::daysOfMon(int month, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = (month >= 1 && month <= 12 ? month : 13)-1;
    return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
void Utils::alocpy(char*& destination, const char* source){
    delete [] destination;
    destination = nullptr;
    if(source != nullptr){
        destination = new char[strlen(source)+1];
        strcpy(destination,source);
    }
    
}
int Utils::getint(const char* prompt){
    
    int value = 0;
    bool isInteger = false;
    
    if(prompt){
        cout << prompt;
        
    }
    while (!isInteger) {
        
        
        cin >> value;
        if (cin.fail()){
            isInteger = false;
            cout << "Invalid Integer, retry: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else{
            isInteger = true;
        }
    }
    
    
    return value;
    
}

int Utils::getint(int min, int max, const char* prompt, const char* errMes){
    int value = 0;
    bool inRange = false;
    
    while (!inRange) {
        value = getint(prompt);
        if(value < min || value > max){
            if(errMes!= nullptr){
                cout << errMes << ", retry: ";
                inRange = false;
                cout <<"Value out of range ["
                << min <<"<=val<=" << max << "]: ";
            }
            else{
                inRange = false;
                cout <<"Value out of range ["
                << min <<"<=val<=" << max << "]: ";
                prompt = nullptr;
                inRange = false;
            }
        }
        else{
            inRange = true;
        }
        
    }
    
    return value;
}

double Utils::getDouble(const char* prompt){
    double value = 0;
    bool isDouble = false;
    
    if(prompt){
        cout << prompt;
        
    }
    while (!isDouble) {
        
        
        cin >> value;
        if (cin.fail()){
            isDouble = false;
            cout << "Invalid number, retry: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else{
            isDouble = true;
        }
    }
    
    
    return value;
    
}
double Utils::getDouble(double min, double max, const char* prompt, const char* errMes){
    double value = 0;
    bool inRange = false;
    
    while (!inRange) {
        value = getDouble(prompt);
        if(value < min || value > max){
            if(errMes!= nullptr){
                cout << errMes << ", retry: ";
                inRange = false;
                cout <<"Value out of range [";
                
                cout.setf(std::ios::fixed);
                cout.precision(2);
                cout << min
                <<"<=val<=";
                cout.setf(std::ios::fixed);
                cout.precision(2);
                cout << max << "]: ";
            }
            else{
                inRange = false;
                cout <<"Value out of range [";
                cout.setf(std::ios::fixed);
                cout.precision(2);
                cout << min
                <<"<=val<=";
                cout.setf(std::ios::fixed);
                cout.precision(2);
                cout << max << "]: ";
                prompt = nullptr;
                inRange = false;
            }
        }
        else{
            inRange = true;
        }
        
    }
    
    return value;
}



}
