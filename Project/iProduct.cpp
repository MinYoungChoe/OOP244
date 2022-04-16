#include "iProduct.h"

namespace sdds {

iProduct::~iProduct(){
    
}

std::ostream& operator <<(std::ostream& ostr, const iProduct& newIproduct){
    newIproduct.display(ostr);
    return ostr;
}
std::istream& operator >>(std::istream& istr, iProduct& newIproduct){
    newIproduct.read(istr);
    return istr;
}
}
