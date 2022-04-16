#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Pack.h"

using namespace std;

namespace sdds {

Pack::Pack(const char* content, int newSize, int newUnitSize, int numOfUnits)
:Container(content, (newSize * newUnitSize), (numOfUnits * newUnitSize)){
    
    if(newUnitSize > 0){
        unitSize = newUnitSize;
    }
    else{
        unitSize = 0;
        setEmpty();
    }
    
}

int Pack::operator +=(int addUnit){
    int added = 0;
    
    added = Container::operator+=(addUnit * unitSize)/unitSize;
    
    return added;
}

int Pack::operator -=(int subtract){
    int added = 0;
    
    added = Container::operator-=(subtract * unitSize)/unitSize;
    
    return added;
}

int Pack::unit(){
    
    return unitSize;
}

int Pack::noOfUnits(){
    
    return volume()/unitSize;
    
}

int Pack::size(){
    
    return capacity()/unitSize;
}

void Pack::clear(int packSize, int newUnitSize, const char* newContent){
    if(newUnitSize > 0){
        Container::clear(packSize * newUnitSize, newContent);
        unitSize = newUnitSize;
    }
    
}

std::ostream& Pack::print(std::ostream& ostr) const{
    
    Container::print(ostr);
    if(Container::operator bool()){
        ostr << ", " << Container::volume()/unitSize << " in a pack of " << Container::capacity() / unitSize;
    }
    
    return ostr;
}

std::istream& Pack::read(std::istream& istr){
    int userInput = 0;
    
    if(*this){
        if(noOfUnits() < size()){
            //            cout << noOfUnits() <<endl;
            //            cout << size() << endl;
            cout << "Add to ";
            cout << *this <<endl;
            userInput = getint(1, size() - noOfUnits(), ">");
            cout << "Added " << (operator+=(userInput)) << endl;
        }
        else{
            cout << "Pack is full!, press <ENTER> to continue...\n";
            istr.ignore(10000, '\n');
        }
    }
    else{
        
        cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
        istr.ignore(1000, '\n');
        
    }
    return istr;
}

istream& operator >>(istream& istr, Pack& newPack){
    newPack.read(istr);
    return istr;
}

ostream& operator <<(ostream& ostr, const Pack& newPack) {
    return newPack.print(ostr);
    
}
}
