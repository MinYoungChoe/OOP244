#ifndef PERISHABLE_H
#define PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds {

class Perishable : public Item{
    Date m_expiry{};
    char* p_description{};
    
public:
    Perishable();
    ~Perishable();
    Perishable(const Perishable& newPerishable);
    Perishable& operator=(const Perishable & newPerishable);
    const Date& expiry()const;
    int readSku(std::istream& istr); //virtual
    std::ofstream& save(std::ofstream& ofstr)const;
    std::ifstream& load(std::ifstream& ifstr);
    std::ostream& display(std::ostream& ostr)const;
    std::istream& read(std::istream& istr);
    
};

}



#endif //PERISHABLE_H
