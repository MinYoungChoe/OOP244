#include <iomanip>
#include <iostream>
#include <fstream>
#include <string.h>
#include "Item.h"
#include "Utils.h"

namespace sdds {


bool Item::linear()const{
    return m_isLinear;
}

Item::Item(){
    m_price = 0;
    m_quantity = 0;
    m_needQuantity = 0;
    itemDescription = nullptr;
    m_isLinear = false;
}

Item::~Item(){
    delete [] itemDescription;
    itemDescription = nullptr;
}

Item::Item(const Item& newItem){
    // No need below
    operator=(newItem);
}

Item& Item::operator=(const Item& newItem){
    if(this!=&newItem){
        if(itemDescription != nullptr){
            delete [] itemDescription;
            itemDescription = nullptr;
        }
        if(newItem.itemDescription != nullptr){
            itemDescription = new char[strlen(newItem.itemDescription)+1];
            strcpy(itemDescription, newItem.itemDescription);
        }
        m_price = newItem.m_price;
        m_quantity = newItem.m_quantity;
        m_needQuantity = newItem.m_needQuantity;
        m_isLinear = newItem.m_isLinear;
        m_status = newItem.m_status;
        m_sku = newItem.m_sku;
        
    }
    return *this;
}

int Item::qtyNeeded()const{
    return m_needQuantity;
}

int Item::qty()const{
    return m_quantity;
}

Item::operator double()const{
    return m_price;
}

Item::operator bool()const{
    
    return m_status;
}

int Item::operator-=(int qty){
    if(qty > 0){
        m_quantity -= qty;
        if(m_quantity < 0){
            m_quantity = 0;
        }
    }
    return m_quantity;
}


int Item::operator+=(int qty){
    if(qty > 0){
        m_quantity += qty;
        if(m_quantity > m_needQuantity){
            m_quantity = m_needQuantity;
        }
    }
    return m_quantity;
}

void Item::clear(){
    m_status.clear();
}

void Item::linear(bool isLinear){
    m_isLinear = isLinear;
}

bool Item::operator==(int sku)const {
    return  m_sku == sku;
}

bool Item::operator==(const char* description)const{
    bool isEqual = false;
    char* tempStr = nullptr;
    
    tempStr = strstr(itemDescription, description);
    if(tempStr != nullptr){
        isEqual = true;
    }
    return isEqual;
}

std::ofstream& Item::save(std::ofstream& ofstr)const{
    if(m_status){
        ofstr << m_sku << "\t" << itemDescription << "\t" << m_quantity << "\t" << m_needQuantity << "\t";
        
        ofstr.setf(std::ios::fixed);
        ofstr.precision(2);
        ofstr << m_price;

    }
    
    return ofstr;
}

std::ifstream& Item::load(std::ifstream& ifstr){
    
    std::string tempDescription;
    
    ifstr >> m_sku;
    ifstr.ignore(1000, '\t');
    
    getline(ifstr, tempDescription, '\t');
    
    if(itemDescription != nullptr){
        delete [] itemDescription;
        itemDescription = nullptr;
    }
    
    itemDescription = new char[strlen(tempDescription.c_str())+1];
    strcpy(itemDescription, tempDescription.c_str());
    
    ifstr >> m_quantity;
    ifstr.ignore(1000, '\t');
    
    ifstr >> m_needQuantity;
    ifstr.ignore(1000, '\t');
    
    ifstr >> m_price;
    ifstr.ignore();
    
    m_status.clear();
    
    if(!ifstr){
        m_status = "Input file stream read failed!";
    }
    
    return ifstr;
    
}

std::ostream& Item::display(std::ostream& ostr)const{
    
    if(m_isLinear){
        ostr <<  std::setfill(' ') << std::setw(5) << std::left << m_sku << " | ";
                
        int i;
        
        for (i = 0; i < 35 && itemDescription[i]; ostr << itemDescription[i++]);
        
        for (; i < 35; ostr << ' ', i++);
        
        ostr << " | " <<  std::setfill(' ') << std::setw(4) << std::right << m_quantity
        
        << " | " <<  std::setfill(' ') << std::setw(4) << std::right << m_needQuantity
        
        << " | ";
        ostr.setf(std::ios::fixed);
        ostr.precision(2);
        ostr << std::setw(7) << m_price << " |";
        
    }
    
    else{
        ostr << "AMA Item:" << std::endl;
        ostr << m_sku << ": " << itemDescription << std::endl;
        ostr << "Quantity Needed: " << m_needQuantity << std::endl;
        ostr << "Quantity Available: " << m_quantity << std::endl;
        ostr << "Unit Price: $";
        
        ostr.setf(std::ios::fixed);
        ostr.precision(2);
        ostr << m_price << std::endl;
        
        ostr << "Needed Purchase Fund: $";
        
        ostr.setf(std::ios::fixed);
        ostr.precision(2);
        ostr << ((m_needQuantity - m_quantity) * m_price)  << std::endl;
        
    }
    
    return ostr;
    
}

int Item::readSku(std::istream& istr){
    
    m_sku = ut.getint(40000, 99999, "SKU: ");
    
    return  m_sku;
    
}

std::istream& Item::read(std::istream& istr){
    
    int tempQuantity = 0;
    int tempNeedQuantity = 0;
    double tempPrice = 0.0;
    
    std::string tempDescription = "";
    
    std::cout << "AMA Item:\n";
    
    std::cout << "SKU: ";
    std::cout << m_sku << std::endl;
    
    std::cout << "Description: ";
    
    istr.ignore();
    std::getline(istr, tempDescription, '\n');
    
    tempNeedQuantity = ut.getint(1, 9999, "Quantity Needed: ");
    
    tempQuantity = ut.getint(0.0, tempNeedQuantity, "Quantity On Hand: ");
    
    tempPrice = ut.getDouble(0.0, 9999.0, "Unit Price: $");
    
    if((strlen(tempDescription.c_str()) <= 35) &&
       (tempNeedQuantity >=1 || tempNeedQuantity <= 9999) &&
       (tempQuantity > 0 || tempQuantity < tempNeedQuantity) &&
       (tempPrice > 0.0 || tempPrice < 9999.0)){
        
        if(itemDescription != nullptr){
            delete [] itemDescription;
            itemDescription = nullptr;
        }
        itemDescription = new char[strlen(tempDescription.c_str())+1];
        strcpy(itemDescription, tempDescription.c_str());
        m_needQuantity = tempNeedQuantity;
        m_quantity = tempQuantity;
        m_price = tempPrice;
    }
    
    m_status.clear();
    
    if(istr.fail()){
        m_status = "Console entry failed!";
    }
    return istr;
}




}
