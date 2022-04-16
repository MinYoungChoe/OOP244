#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>
#include "Status.h"

namespace sdds {

void Status::allocateAndCopy(const char* newDescription){
    if(newDescription){
        if(m_description != nullptr){
            delete [] m_description;
            m_description = nullptr;
        }
        m_description = new char[strlen(newDescription)+1];
        strcpy(m_description, newDescription);
    }
}
void Status::setEmpty(){
    delete [] m_description;
    m_description = nullptr;
}
Status& Status::clear(){
    delete [] m_description;
    m_description = nullptr;
    return *this;
}

Status::Status(){
    m_description = nullptr;
    optionalStatusCode = 0;
}

Status::Status(const char* description){
    m_description = nullptr;
    optionalStatusCode = 0;
    
    m_description = new char[strlen(description)+1];
    strcpy(m_description,description);
    optionalStatusCode = 0;
}

Status::Status(const Status& otherStatus){
    if(otherStatus.m_description != nullptr){
        m_description = new char[strlen(otherStatus.m_description)+1];
        strcpy(m_description, otherStatus.m_description);
        optionalStatusCode = otherStatus.optionalStatusCode;
    }
}

Status& Status::operator =(const Status& otherStatus){
    if(this != &otherStatus){
        if (otherStatus.m_description) {
            allocateAndCopy(otherStatus.m_description);
        }
        else {
            delete[] m_description;
            m_description = nullptr;
        }
        optionalStatusCode = otherStatus.optionalStatusCode;
    }
    return *this;
}


Status& Status::operator =(int code){
    optionalStatusCode = code;
    return *this;
}

Status& Status::operator =(const char* description){
    allocateAndCopy(description);
    return *this;
}
Status::~Status(){
    delete [] m_description;
    m_description = nullptr;
}

Status::operator int() const{
    return optionalStatusCode;
}

Status::operator const char*() const{
    return m_description;
}

Status::operator bool() const{
    
    return m_description == nullptr;
}

std::ostream& operator <<(std::ostream& ostr, const Status& otherStaus) {
    int returnedCode = ((int)(otherStaus));
    
    if(returnedCode != 0){
        ostr << "ERR#" << returnedCode << ": ";
    }
    ostr << ((const char*)(otherStaus));
    
    return ostr;
}

}
