#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"

namespace sdds {

class Pack : public Container{
    
    int unitSize;
    
public:
    Pack(const char* content, int newSize, int newUnitSize = 330, int numOfUnits = 0);
    int operator +=(int addUnit);
    int operator -=(int subtract);
    int unit();
    int noOfUnits();
    int size();
    void clear(int packSize, int unitSize, const char* newContent);
    std::ostream& print(std::ostream& ostr) const;
    std::istream& read(std::istream& istr);
    
};
std::istream& operator >>(std::istream& istr, Pack& newPack);
std::ostream& operator <<(std::ostream& ostr, const Pack& newPack);


}

#endif //SDDS_PACK_H
