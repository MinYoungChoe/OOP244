#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <stdio.h>
#include "LblShape.h"

namespace sdds {

class Rectangle : public LblShape{
    int m_width;
    int m_height;
public:
    Rectangle();
    Rectangle(const char* newLabel, int newWidth=0, int newHeight=0);
    ~Rectangle();
    void getSpecs(std::istream &istr);
    void draw(std::ostream& ostr)const;

};

}

#endif /* RECTANGLE_H */
