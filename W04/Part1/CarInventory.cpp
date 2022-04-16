/*
 OOB244 Workshop4 part1
 Min Young Choe
 ID : 133607218 Email:mchoe@myseneca.ca
 DATE :
 */
#include <iostream>
#include <string.h>
#include<iomanip>

#include "CarInventory.h"
using namespace std;


namespace sdds{

void CarInventory::resetInfo(){
    m_type = nullptr;
    m_brand = nullptr;
    m_model = nullptr;
    m_year = 0;
    m_code = 0;
    m_price = 0;
}

CarInventory::CarInventory(){
    resetInfo();
    
}

CarInventory::CarInventory(const char* type, const char* brand,
                           const char* model, int year, int code, double price){
    
    if ((type!=nullptr && brand != nullptr && model != nullptr)
        && (year >= 1990 && code < 1000 && price > 0)){
        m_type = new char[strlen(type)+1];
        strcpy(m_type, type);
        m_brand = new char[strlen(brand)+1];
        strcpy(m_brand, brand);
        m_model = new char[strlen(model)+1];
        strcpy(m_model, model);
        m_year = year;
        m_code = code;
        m_price = price;
    }
    else {
        this->resetInfo();
        
    }
}


CarInventory::~CarInventory(){
    delete[] m_type;
    m_type = nullptr;
    delete [] m_brand;
    m_brand = nullptr;
    delete [] m_model;
    m_model = nullptr;
}

CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price){
    delete[] m_type;
    m_type = nullptr;
    delete [] m_brand;
    m_brand = nullptr;
    delete [] m_model;
    m_model = nullptr;
    
    m_type = new char[strlen(type)+1];
    strcpy(m_type, type);
    m_brand = new char[strlen(brand)+1];
    strcpy(m_brand, brand);
    m_model = new char[strlen(model)+1];
    strcpy(m_model, model);
    m_year = year;
    m_code = code;
    m_price = price;
    
    
    
    return *this;
}

void CarInventory::printInfo() const{
    
    
    cout <<"| " << setw(10) << left << m_type
    
    << " | " << setw(16) << left << m_brand
    
    << " | " << setw(16) << left << m_model
    
    << " | " << setw(4) << m_year
    
    << " |  " << setw(3) << m_code
    
    << " |" << setw(10) << right << fixed << setprecision(2) << m_price << " |" << endl;
    //    cout << "| ";
    //    cout.setf(ios::left);
    //    cout.width(11);
    //    cout << m_type<<"| ";
    //
    //    cout.setf(ios::left);
    //    cout.width(16);
    //    cout<< m_brand <<" | ";
    //
    //    cout.setf(ios::left);
    //    cout.width(16);
    //    cout << m_model << " | ";
    //
    //    cout.setf(ios::right);
    //    cout.width(4);
    //    cout << m_year << " | ";
    //
    //    cout.setf(ios::right);
    //    cout.width(3);
    //    cout<< m_code <<"  |  ";
    //
    //    cout.width(8);
    //    cout.setf(ios::fixed);
    //    cout.setf(ios::right);
    //    cout.precision(2);
    //    cout << m_price <<" |" <<endl;
}

bool CarInventory::isValid() const{
    
    bool isValid = false;
    
    if ((m_type!=nullptr && m_brand != nullptr && m_model != nullptr)
        && (m_year >= 1990 && m_code < 1000 && m_price > 0)){
        isValid = true;
        
    }
    else{
        isValid = false;
    }
    
    return isValid;
    
}
bool CarInventory::isSimilarTo(const CarInventory& car) const{
    bool isSimillar = false;
    
    if((*this).m_type != nullptr && (*this).m_brand != nullptr && (*this).m_model != nullptr){
        if(strcmp((*this).m_type,car.m_type) || strcmp((*this).m_brand, car.m_brand)
           || strcmp((*this).m_model,car.m_model) || ((*this).m_year == car.m_year)){
            isSimillar = true;
        }
        else{
            isSimillar = false;
        }
    }
    
    
    return isSimillar;
}
bool find_similar(CarInventory car[], const int num_cars){
    
    bool foundSimilar = false;
    
    
    for (int i = 0; i < num_cars; i++){
        for (int j = i+1; j < num_cars; j++){
            if(car[i].isSimilarTo(car[j])){
                foundSimilar = true;
            }
            else{
                foundSimilar = false;
            }
            
        }
    }
    
    return foundSimilar;
}

}
