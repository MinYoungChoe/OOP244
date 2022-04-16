#ifndef Line_h
#define Line_h
#include <stdio.h>
#include "LblShape.h"

namespace sdds {

class Line : public LblShape{
  
    int m_length;
    
public:
    Line();
    Line(const char* label, int length);
    ~Line();
    void getSpecs(std::istream &istr);
    void draw(std::ostream& ostr)const;
};

}


#endif /* Line_h */
