#include <iostream>
#include <fstream>
#include <string.h>
#include "Perishable.h"
#include "Utils.h"

namespace sdds {

Perishable::Perishable(){
    p_description = nullptr;
    
}

Perishable::~Perishable(){
    delete [] p_description;
    p_description = nullptr;
}

Perishable::Perishable(const Perishable& newPerishable){
    operator=(newPerishable);
}

Perishable& Perishable::operator=(const Perishable & newPerishable){
    if(this!=&newPerishable){
        Item::operator=(newPerishable);
        m_expiry = newPerishable.m_expiry;
        if(p_description){
            delete [] p_description;
            p_description = nullptr;
        }
        if(newPerishable.p_description != nullptr){
            p_description = new char[strlen(newPerishable.p_description)+1];
            strcpy(p_description, newPerishable.p_description);
        }
    }
    return *this;
}

const Date& Perishable::expiry()const{
    return m_expiry;
}

int Perishable::readSku(std::istream& istr){
    m_sku = ut.getint(10000, 39999, "SKU: ");
    return m_sku;
}

std::ofstream& Perishable::save(std::ofstream& ofstr)const{
    
    if(*this){
        Item::save(ofstr);
       
        Date exp = m_expiry;
        exp.formatted(false);
        ofstr << '\t' << (p_description && p_description[0] ? p_description : "") << '\t' << exp;
    }
    return ofstr;
}

std::ifstream& Perishable::load(std::ifstream& ifstr){
    
    std::string tempDescription;
    
    Item::load(ifstr);
    
    getline(ifstr, tempDescription, '\t');
    if(p_description != nullptr){
        delete [] p_description;
        p_description = nullptr;
    }
    p_description = new char[strlen(tempDescription.c_str())+1];
    strcpy(p_description, tempDescription.c_str());
    
    ifstr >> m_expiry;
    ifstr.ignore(1000, '\n');
    
    m_status.clear();
    if(!ifstr){
        m_status = "Input file stream read (perishable) failed!";
    }
    
    return ifstr;
    
}

std::ostream& Perishable::display(std::ostream& ostr)const{
    
    Date exp = m_expiry;
    exp.formatted(false);
    
    if(!m_status){
        ostr << m_status;
    }
    else{
        if(linear()){
            Item::display(ostr);
            exp.formatted(true);
            if(p_description != nullptr && p_description[0] != '\0'){
                ostr << "*" << exp;
            }
            else{
                ostr << " " << exp;
            }
        }
        else{
            ostr << "Perishable ";
            Item::display(ostr);
            ostr << "Expiry date: ";
            exp.formatted(true);
            //to match output of ms51
            ostr << exp << "\n";
            if(p_description != nullptr && p_description[0] != '\0'){
                ostr << "Handling Instructions: " << p_description << std::endl;
            }
            
        }
    }
    return ostr;
}

std::istream& Perishable::read(std::istream& istr){
    std::string tempDescription;
    
    Item::read(istr);
    delete [] p_description;
    p_description = nullptr;
    
    std::cout << "Expiry date (YYMMDD): ";
    istr >> m_expiry;
    istr.ignore(1000, '\n');
    
    
    std::cout << "Handling Instructions, ENTER to skip: ";
    if (istr.peek() != '\n'){
        std::getline(istr, tempDescription, '\n');
        if(p_description != nullptr){
            delete [] p_description;
            p_description = nullptr;
        }
        p_description = new char[strlen(tempDescription.c_str())+1];
        strcpy(p_description, tempDescription.c_str());
    }
    
    if (istr.fail()){
        m_status = "Perishable console date entry failed!";
    }
    std::cout << std::endl;
    return istr;
}

}
