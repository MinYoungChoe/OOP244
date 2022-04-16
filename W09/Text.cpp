#include <iomanip>
#include <iostream>
#include <fstream>
#include <string.h>
#include "Text.h"

namespace sdds {

void Text::setEmpty(){
    if(m_content){
        delete [] m_content;
        m_content = nullptr;
    }
}

Text::Text(){
    m_content = nullptr;
}

Text::Text(const char* newContent){
    if(newContent){
        m_content = new char[strlen(newContent)+1];
        strcpy(m_content, newContent);
        
    }
    else{
        m_content = nullptr;
    }
}
Text::Text(const Text& newText){
    
    m_content = nullptr;
    *this = newText;
}

Text& Text::operator=(const Text& newText){
    if(this != &newText){
        if(newText.m_content){
            if(m_content){
                setEmpty();
            }
            m_content = new char[strlen(newText.m_content)+1];
            strcpy(m_content, newText.m_content);
        }
    }
    return *this;
}
Text::~Text(){
    setEmpty();
}

const char& Text::operator[](int index)const{
    
    return m_content[index];
}

int Text::getFileLength(std::istream& is)  {
    int len{};
    if (is) {
        std::streampos cur = is.tellg();
        is.seekg(0, ios::end);
        len = is.tellg();
        is.seekg(cur);
    }
    return len;
}

void Text::read(std::istream &istr){
    
    int tempLength = getFileLength(istr);
    int i=0;
    
    if(m_content){

        setEmpty();
    }
    m_content = new char[tempLength+1];
    
    for(i=0; i < tempLength; i++){
        istr.get(m_content[i]);
    }
    m_content[i] = '\0';
    
    if(i){
        istr.clear();
    }
    
}

ostream& Text::write(ostream& ostr) const{
    if(m_content){
        ostr << m_content;
    }
    return ostr;
}

istream& operator >>(istream& istr, Text& newText){
    newText.read(istr);
    return istr;
}

ostream& operator <<(ostream& ostr, const Text& newText){
    return newText.write(ostr);
}
}
