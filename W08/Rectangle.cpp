#include "Rectangle.h"
#include <iostream>
#include <iomanip>
#include <string.h>

namespace sdds {

Rectangle::Rectangle(){
    m_width = 0;
    m_height = 0;
}

Rectangle::Rectangle(const char* newLabel, int newWidth, int newHeight):LblShape(newLabel){
    if(newHeight < 3 || newWidth <= ((int)strlen(label())+2)){
        m_width = 0;
        m_height = 0;
    }
    else{
        m_width = newWidth;
        m_height = newHeight;
    }
    
}

Rectangle::~Rectangle(){
    
}

void Rectangle::getSpecs(std::istream &istr){
    LblShape::getSpecs(istr);
    istr >> m_width;
    istr.ignore(1000, ',');
    istr >> m_height;
    istr.clear(); // reset
    istr.ignore(1000, '\n');
}

void Rectangle::draw(std::ostream& ostr)const{
    int tempWidth = 0;
    int tempHeight = 0;
    if(label() != nullptr && m_width > 0 && m_height > 0){
        
        ostr << "+";
        for(int i = 0; i < m_width-2; i++){
            std::cout << "-";
        }
        ostr << "+" << std::endl;
        ostr << "|" << label();
        tempWidth = (int)m_width-2-(strlen(label()));
        for(int i = 0; i < tempWidth; i++){
            std::cout << " ";
        }
        ostr <<"|" << std::endl;
        
        tempHeight = m_height - 2;
        for(int i = 0; i < tempHeight-1; i++){
            std::cout << "|";
            for(int i = 0; i < m_width-2; i++){
                std::cout << " ";
            }
            std::cout <<"|" << std::endl;
        }
        ostr << "+";
        for(int i = 0; i < m_width-2; i++){
            std::cout << "-";
        }
        ostr << "+";;
        
    }
    
}
}
