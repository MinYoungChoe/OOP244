#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include <stdio.h>
#include "Shape.h"

namespace sdds {
class LblShape : public Shape{
    char* m_label;
    
protected:
    const char* label()const;
    
public:
    LblShape();
    LblShape(const char* newLabel);
    ~LblShape();
    LblShape(const LblShape& source) = delete;
    LblShape& operator=(const LblShape& source) = delete;
    void getSpecs(std::istream &istr);
    
};

}

#endif //



