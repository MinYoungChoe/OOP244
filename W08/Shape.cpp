#include "Shape.h"

namespace sdds {

Shape::~Shape(){
    
}
std::istream& operator >>(std::istream& istr, Shape& newShape){
    newShape.getSpecs(istr);
    return istr;
}
std::ostream& operator <<(std::ostream& ostr, const Shape& newShape){
    newShape.draw(ostr);
    return ostr;
}


}
