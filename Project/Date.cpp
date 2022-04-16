#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>
#include "Date.h"
#include "Utils.h"

namespace sdds{

bool Date::validDate(){
    bool isVaild = false;
    
    if(m_year < 2022 || m_year > maximumYearValue){
        State = "Invalid year in date";
        State = 1;
        isVaild = false;
    }
    else if(m_month < 1 || m_month > 12){
        State = "Invalid month in date";
        State = 2;
        isVaild = false;
        
    }
    else if(m_day<1 || m_day > ut.daysOfMon(m_month, m_year)){
        State = "Invalid day in date";
        State = 3;
        isVaild = false;
    }
    else{
        State = "";
        State = 0;
        isVaild = true;
    }
    return isVaild;
}

int Date::uniqueInt() const{
    return (m_year * 372 + m_month * 31 + m_day);
}

Date::Date(){
    m_year = 0;
    m_month = 0;
    m_day = 0;
    Formatted = true;
    ut.getSystemDate(&m_year, &m_month, &m_day);
}

Date::Date(int newYear, int newMonth, int newDay){
    m_year = 0;
    m_month = 0;
    m_day = 0;
    Formatted = true;
    
    if((newYear >= 2022 || newYear <= maximumYearValue)
       && (newMonth >= 1 || newMonth <= 12)
       && (newDay >=1 || newDay <=31)){
        m_year = newYear;
        m_month = newMonth;
        m_day = newDay;
    }
    
}

bool Date::operator ==(const Date& right){
    return uniqueInt() == right.uniqueInt();
}

bool Date::operator !=(const Date& right){
    return uniqueInt() != right.uniqueInt();
}

bool Date::operator <(const Date& right){
    return uniqueInt() < right.uniqueInt();
}

bool Date::operator >(const Date& right){
    return uniqueInt() > right.uniqueInt();
}

bool Date::operator <=(const Date& right){
    return uniqueInt() <= right.uniqueInt();
}

bool Date::operator >=(const Date& right){
    return uniqueInt() >= right.uniqueInt();
}
const Status& Date::state(){
    return this->State;
}

Date& Date::formatted(bool newFormat){
    this->Formatted = newFormat;
    return *this;
}
Date::operator bool() const{
    return this->State;
}

std::ostream& Date::write(std::ostream& ostr) const{
    if(Formatted){
        ostr << m_year << "/";
        
        ostr.width(2); ostr.fill('0');
        ostr << m_month << "/";
        
        ostr.width(2); ostr.fill('0');
        ostr<< m_day;
    }
    else{
        ostr.width(2); ostr.fill('0');
        ostr << m_year % 100;
        
        ostr.width(2); ostr.fill('0');
        ostr << m_month << m_day;
    }
    
    return ostr;
}

std::istream& Date::read(std::istream& istr) {

    State.clear();
    
    unsigned int value{};
    
    istr >> value;
    
    if (istr) {
        
        m_day = value % 100;
        
        if (value){
            
            value = value / 100;
            m_month = value % 100;
            
        }
        
        if (value){
            
            value = value / 100;
            m_year = value % 100;
            m_year += 2000;
            
        }
        
        if (m_year == 2000){
            ut.getSystemDate(&m_year);
        }
        
        if (!validDate()){
            istr.setstate(std::ios::badbit);
        }
        
    }
    
    else {
        State = "Invalid date value";
    }
    
    return istr;
    
}

std::ostream& operator <<(std::ostream& ostr, const Date& otherDate){
    otherDate.write(ostr);
    return ostr;
}

std::istream& operator >>(std::istream& istr, Date& otherDate){
    otherDate.read(istr);
    return istr;
}

}
