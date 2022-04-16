#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <stdio.h>
#include <iostream>

namespace sdds {

class Shape{
    
public:
    virtual void draw(std::ostream& ostr)const = 0;
    virtual void getSpecs(std::istream& istr) = 0;
    virtual~Shape();
};

std::ostream& operator <<(std::ostream& ostr, const Shape& newShape);
std::istream& operator >>(std::istream& istr, Shape& newShape);

}

#endif //SDDS_SHAPE_H
