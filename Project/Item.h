#ifndef ITEM_H
#define ITEM_H
#include <stdio.h>
#include <iostream>
#include "Status.h"
#include "iProduct.h"

namespace sdds {

class Item : public iProduct{
    double m_price{};
    int m_quantity{};
    int m_needQuantity{};
    char* itemDescription{};
    bool m_isLinear{};
    
protected:
    Status m_status{ "Empty Item" };
    int m_sku{};
    bool linear()const;
    
public:
    Item();
    ~Item();
    Item(const Item& newItem);
    int readSku(std::istream& istr);
    int operator-=(int qty);
    int operator+=(int qty);
    void linear(bool isLinear);
    operator double()const;
    operator bool()const;
    int qtyNeeded()const;
    int qty()const;
    Item& operator=(const Item & newItem);
    void clear();
    std::ofstream& save(std::ofstream& ofstr)const;
    std::ifstream& load(std::ifstream& ifstr);
    std::ostream& display(std::ostream& ostr)const;
    std::istream& read(std::istream& istr);
    bool operator==(int sku)const;
    bool operator==(const char* description)const;
    
};

}


#endif //ITEM_H
