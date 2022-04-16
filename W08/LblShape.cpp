#include <iostream>
#include <string.h>
#include "LblShape.h"

namespace sdds {

const char* LblShape::label()const{
    return m_label;
}

LblShape::LblShape(){
    m_label = nullptr;
}

LblShape::LblShape(const char* newLable){
    if(newLable){
        m_label = new char[strlen(newLable)+1];
        strcpy(m_label, newLable);
    }
    else{
        m_label = nullptr;
    }
}

LblShape::~LblShape(){
    if(m_label != nullptr){
        delete [] m_label;
        m_label = nullptr;
    }
}

void LblShape::getSpecs(std::istream &istr){
    char tempLabel[100];
    tempLabel[0] = '\0';
    
    istr.get(tempLabel, 1000, ',');
    istr.clear();
    istr.ignore(1000, ',');
    
    if(m_label != nullptr){
        delete [] m_label;
        m_label = nullptr;
    }
    m_label = new char[strlen(tempLabel)+1];
    strcpy(m_label, tempLabel);
}

}
