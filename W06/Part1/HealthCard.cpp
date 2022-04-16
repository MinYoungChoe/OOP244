#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HealthCard.h"

using namespace std;
namespace sdds {

bool HealthCard::validID(const char* name, long long number, const char vCode[] , const char sNumber[]) const{
    bool isValid = false;
    
    if(name != nullptr && (number > 999999999 && number < 9999999999)
       && (strlen(vCode) == 2) && (strlen(sNumber) == 9)){
        isValid = true;
    }
    return isValid;
}

void HealthCard::setEmpty(){
    delete [] m_name;
    m_name = nullptr;
}

void HealthCard::allocateAndCopy(const char* name){
    if(m_name){
        delete [] m_name;
        m_name = nullptr;
    }
    m_name = new char[strlen(name)+1];
    strcpy(m_name, name);
}

void HealthCard::extractChar(istream& istr, char ch) const{
    char next = istr.peek();
    if(next == ch){
        istr.ignore();
    }
    else{
        istr.ignore(1000, ch);
        istr.setstate(ios::failbit);
    }
}

ostream& HealthCard::printIDInfo(ostream& ostr)const{
    ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
    return ostr;
}

void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]){
    if(validID(name, number, vCode, sNumber)){
        allocateAndCopy(name);
        m_number = number;
        strcpy(m_vCode,vCode);
        strcpy(m_sNumber, sNumber);
    }
    else{
        setEmpty();
    }
    
}

HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]){
    set(name, number, vCode, sNumber);
}

HealthCard::HealthCard(const HealthCard& hc){
    if(validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)){
        
        if(m_name != nullptr){
            delete [] m_name;
            m_name = nullptr;
        }
        m_name = new char[strlen(hc.m_name)+1];
        strcpy(m_name, hc.m_name);
        m_number = hc.m_number;
        strcpy(m_vCode, hc.m_vCode);
        strcpy(m_sNumber, hc.m_sNumber);
    }
}

HealthCard& HealthCard::operator=(const HealthCard& hc){
    if(this!= &hc){
        if(validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)){
            
            delete [] m_name;
            m_name = new char[strlen(hc.m_name)+1];
            strcpy(m_name, hc.m_name);
            m_number = hc.m_number;
            strcpy(m_vCode, hc.m_vCode);
            strcpy(m_sNumber, hc.m_sNumber);
        }
        else {
            setEmpty();
        }
        
    }
    return *this;
    
}

HealthCard::~HealthCard(){
    delete [] m_name;
}

HealthCard::operator bool() const{
    return m_name;
}

ostream& HealthCard::print(ostream& ostr, bool toFile) const{
    if (*this) {
        
        if (toFile) {
            
            ostr << m_name << ",";
            
        }
        
        else {
            
            ostr.width(50);
            
            ostr.fill('.');
            
            ostr.setf(ios::left);
            
            ostr << m_name;
            
            ostr.unsetf(ios::left);
            
            ostr.fill(' ');
            
        }
        
        printIDInfo(ostr);
        
        if (toFile) ostr << endl;
        
    }
    
    return ostr;
    
}

istream& HealthCard::read(std::istream& istr){
    
    char localName[56];
    localName[0] = '\0';
    
    long long localNumber = 0;
    
    char localCode[3];
    localCode[0] = '\0';
    
    char localSnumber[10];
    localSnumber[0] = '\0';
    
    
    istr.get(localName, MaxNameLength, ',');
    extractChar(istr, ',');
    
    if(istr){
        istr >> localNumber;
        extractChar(istr, '-');
        if(istr){
            istr.get(localCode, 3, ',');
            extractChar(istr, ',');
            if(istr){
                istr.get(localSnumber, 10, '\n');
            }
        }
    }
    if(istr){
        set(localName, localNumber, localCode, localSnumber);
        
    }
    istr.clear();
    istr.ignore(1000, '\n');
    
    return istr;
}

ostream& operator<<(ostream& ostr, const HealthCard& hc){
    if(hc){
        hc.print(ostr,false);
    }
    else{
        ostr << "Invalid Health Card Record";
    }
    
    return ostr;
    
}

istream& operator>>(istream& istr, HealthCard& hc){
    hc.read(istr);
    return istr;
}

}



