#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Name.h"

using namespace std;

namespace sdds {

void Name::setEmpty(){
    delete [] m_firstName;
    m_firstName = nullptr;
    
    delete [] m_middleName;
    m_middleName = nullptr;
    
    delete [] m_lastName;
    m_lastName = nullptr;
}

Name::Name(){
    m_firstName = nullptr;
    m_middleName = nullptr;
    m_lastName = nullptr;
}

Name::Name(const char* firstName){
    if(firstName != nullptr && firstName[0] !='\0'){
        m_firstName = new char[strlen(firstName)+1];
        strcpy(m_firstName, firstName);
    }
    else{
        m_firstName = nullptr;
    }
}

Name::Name(const char* firstName, const char* lastName){
    if(firstName != nullptr && firstName[0] !='\0'
       && lastName != nullptr && lastName[0] !='\0'){
        m_firstName = new char[strlen(firstName)+1];
        strcpy(m_firstName, firstName);
        m_lastName = new char[strlen(lastName)+1];
        strcpy(m_lastName, lastName);
    }
    else{
        m_firstName = nullptr;
        m_lastName = nullptr;
    }
}

Name::Name(const char* firstName, const char* middleName, const char* lastName){
    if(firstName != nullptr && firstName[0] != '\0'
       && middleName != nullptr && middleName[0] != '\0'
       && lastName != nullptr && lastName[0] != '\0'){
        m_firstName = new char[strlen(firstName)+1];
        strcpy(m_firstName, firstName);
        m_middleName = new char[strlen(middleName)+1];
        strcpy(m_middleName, middleName);
        m_lastName = new char[strlen(lastName)+1];
        strcpy(m_lastName, lastName);
    }
    else{
        m_firstName = nullptr;
        m_middleName = nullptr;
        m_lastName = nullptr;
        
    }
    
}

Name::Name(const Name& newName){
    if(newName){
        
        if(m_firstName != nullptr){
            delete [] m_firstName;
            m_firstName = nullptr;
            if(m_middleName != nullptr){
                delete [] m_middleName;
                m_middleName = nullptr;
                if(m_lastName != nullptr){
                    delete [] m_lastName;
                    m_lastName = nullptr;
                    
                }
            }
        }
        m_firstName = new char[strlen(newName.m_firstName)+1];
        strcpy(m_firstName, newName.m_firstName);
        if(newName.m_middleName){
            m_middleName = new char[strlen(newName.m_middleName)+1];
            strcpy(m_middleName, newName.m_middleName);
        }
        if(newName.m_lastName){
            m_lastName = new char[strlen(newName.m_lastName)+1];
            strcpy(m_lastName, newName.m_lastName);
        }
    }
}

Name& Name::operator=(const Name& newName){
    if(this != &newName){
        if(newName.m_firstName != nullptr && newName.m_firstName[0] != '\0'
           && newName.m_middleName != nullptr && newName.m_middleName[0] != '\0'
           && newName.m_lastName != nullptr && newName.m_lastName[0] != '\0'){
            
            if(m_firstName != nullptr){
                delete [] m_firstName;
                m_firstName = nullptr;
                if(m_middleName != nullptr){
                    delete [] m_middleName;
                    m_middleName = nullptr;
                    if(m_lastName != nullptr){
                        delete [] m_lastName;
                        m_lastName = nullptr;
                        
                    }
                }
            }
            m_firstName = new char[strlen(newName.m_firstName)+1];
            strcpy(m_firstName, newName.m_firstName);
            m_middleName = new char[strlen(newName.m_middleName)+1];
            strcpy(m_middleName, newName.m_middleName);
            m_lastName = new char[strlen(newName.m_lastName)+1];
            strcpy(m_lastName, newName.m_lastName);
        }
    }
    return *this;
}

Name::~Name(){
    
    delete [] m_firstName;
    m_firstName = nullptr;
    
    delete [] m_middleName;
    m_middleName = nullptr;
    
    delete [] m_lastName;
    m_lastName = nullptr;
    
}

void Name::setShort(bool m_value){
    m_short = m_value;
    
}

Name& Name::operator+=(const char* adding){
    bool hasSpace = false;
    
    for(int i = 0; i < strlen(adding); i++){
        if(adding[i] == ' '){
            hasSpace = true;
        }
    }
    
    if(adding != nullptr && adding[0] != '\0'){
        if(!hasSpace){
            if(m_firstName == nullptr){
                m_firstName = new char[strlen(adding)+1];
                strcpy(m_firstName, adding);
            }
            else if(m_middleName == nullptr){
                m_middleName = new char[strlen(adding)+1];
                strcpy(m_middleName, adding);
            }
            else if(m_lastName == nullptr){
                m_lastName = new char[strlen(adding)+1];
                strcpy(m_lastName, adding);
            }
            else{
                setEmpty();
            }
        }
        else{
            setEmpty();
        }
    }
    return *this;
}

void Name::extractChar(istream& istr, char ch) const{
    char next = istr.peek();
    if(next == ch){
        istr.ignore();
    }
    else{
        istr.ignore(1000, ch);
        istr.setstate(ios::failbit);
    }
}

void Name::set(const char* newFirstName){
    if(newFirstName != nullptr && newFirstName[0] !='\0'){
        m_firstName = new char[strlen(newFirstName)+1];
        strcpy(m_firstName, newFirstName);
    }
    else{
        setEmpty();
    }
    
}

void Name::set(const char* newFirstName, const char* newLastName){
    if(newFirstName != nullptr && newFirstName[0] !='\0'
       && newLastName != nullptr && newLastName[0] !='\0'){
        
        m_firstName = new char[strlen(newFirstName)+1];
        strcpy(m_firstName, newFirstName);
        
        
        m_lastName = new char[strlen(newLastName)+1];
        strcpy(m_lastName, newLastName);
        
    }
    else{
        setEmpty();
    }
}

void Name::set(const char* newFirstName, const char* newMiddleName, const char* newLastName){
    
    if(newFirstName != nullptr && newFirstName[0] != '\0'){
        m_firstName = new char[strlen(newFirstName)+1];
        strcpy(m_firstName, newFirstName);
    }
    if(newMiddleName != nullptr && newMiddleName[0] != '\0'){
        m_middleName = new char[strlen(newMiddleName)+1];
        strcpy(m_middleName, newMiddleName);
    }
    if(newLastName != nullptr && newLastName[0] != '\0'){
        m_lastName = new char[strlen(newLastName)+1];
        strcpy(m_lastName, newLastName);
    }
    
}

istream& Name::read(istream& istr){
    
    string tempFirstName;
    string tempMiddleName;
    string tempLastName;
    
    int c = 1;
    
    setEmpty();
    istr >> tempFirstName;
    
    if (istr.peek() == ' '){
        istr >> tempMiddleName;
        c++;
    }
    
    if (istr.peek() == ' '){
        istr >> tempLastName;
        c++;
    }
    
    if (istr.peek() == '\n'){
        if(c==1){
            set(tempFirstName.c_str());
        }
        else if (c == 2){
            set(tempFirstName.c_str(), tempMiddleName.c_str());
        }
        
        else{
            set(tempFirstName.c_str(), tempMiddleName.c_str(), tempLastName.c_str());
        }
        
        istr.ignore();
    }
    tempFirstName.clear();
    tempMiddleName.clear();
    tempLastName.clear();
    
    return istr;
    
}

ostream& Name::display(ostream& ostr) const {
    
    if (*this){
        ostr << m_firstName;
        if (m_middleName){
            if (m_short)
                ostr << " " << m_middleName[0] << ".";
            else{
                ostr << " " << m_middleName;
            }
        }
        
        if (m_lastName){
            ostr << " " << m_lastName;
        }
    }
    
    else{
        ostr << "Bad Name";
    }
    
    return ostr;
    
}

Name::operator bool() const{
    return m_firstName;
}


istream& operator >>(istream& istr, Name& newName){
    newName.read(istr);
    return istr;
}

ostream& operator <<(ostream& ostr, const Name& newName) {
    
    return newName.display(ostr);
    
}
}
