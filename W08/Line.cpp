#include "Line.h"

namespace sdds {

Line::Line(){
    m_length = 0;
}

Line::Line(const char* label, int length):LblShape(label){
    m_length = length;
}

Line::~Line(){
    
}

void Line::getSpecs(std::istream &istr){
    LblShape::getSpecs(istr);
    istr >> m_length;
    istr.clear(); // reset
    istr.ignore(1000, '\n');
    
}

void Line::draw(std::ostream& ostr)const{
    if(m_length > 0 && label() != nullptr){
        std::cout << label() << std::endl;
        for(int i = 0; i < m_length; i++){
            std::cout << "=";
        }
    }
    
}

}
