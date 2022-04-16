#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Container.h"

using namespace std;
namespace sdds {

int getint(const char* prompt){
    
    int value = 0;
    bool isInteger = false;
    
    if(prompt){
        cout << prompt <<" ";
    }
    while (!isInteger) {
        
        cin >> value;
        
        if (cin.fail()){
            isInteger = false;
            cout << "Invalid Integer, retry: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        
        else{
            isInteger = true;
        }
    }
    
    
    return value;
    
}

int getint(int min, int max, const char* prompt, const char* errMes){
    int value = 0;
    bool inRange = false;
    
    while (!inRange) {
        value = getint(prompt);
        if(value < min || value > max){

            if(errMes){
                cout << errMes << ", retry: ";
            }
            else{
                prompt = nullptr;
            }
            cout <<"Value out of range ["
                 << min <<"<=val<=" << max << "]: ";
            inRange = false;
        }
        else{
            inRange = true;
        }
        
    }
    
    return value;
}

void Container::setEmpty(){
    m_content[0] = '\0';
    m_capacity = 0;
    m_volume = 0;
}

int Container::capacity() const{
    return m_capacity;
}

int Container::volume() const{
    return m_volume;
}

Container::Container(){
    m_content[0] = '\0';
    m_capacity = 0;
    m_volume = 0;
    
}

void Container::copy(const char* newContent, int &newCapacity, int newVolume){
    
    strcpy(m_content,newContent);
    m_capacity = newCapacity;
    m_volume = newVolume;
    
}

Container::Container(const char* newContent, int newCapacity){
    
    if(newContent != nullptr && strlen(newContent) < 51){
        copy(newContent, newCapacity, 0);
    }
    else{
        setEmpty();
    }
    
}

Container::Container(const char* newContent, int newCapacity, int newVolume){
    if(newContent != nullptr && strlen(newContent) < 51 && newVolume < newCapacity){
        copy(newContent, newCapacity, newVolume);
    }
    else{
        setEmpty();
    }

}

int Container::operator +=(int addVolume){
    
    int beforeVolume = m_volume;
    int added = 0;
    if (addVolume > 0 && m_volume < m_capacity ){
        m_volume += addVolume;
        if( m_volume > m_capacity){
            m_volume = m_capacity;
        }
        
    }
    added = m_volume - beforeVolume;
    
    return added;
}

int Container::operator -=(int subtract){
    
    int beforeVolume = m_volume;
    int subtracted = 0;
    
    if(subtract > 0){
        m_volume -= subtract;
        
        if( m_volume < 0){
            m_volume = 0;
        }
    }
    
    subtracted = beforeVolume - m_volume;
    
    return subtracted;
}

Container::operator bool() const{
    return m_capacity > 0;
}

void Container::clear(int newCapacity, const char* newContent){
    if(newCapacity > 0 && newContent[0] != '\0' && strlen(newContent) < 51){
        m_capacity = newCapacity;
        strcpy(m_content, newContent);
    }
    else{
        setEmpty();
    }
}

ostream& Container::print(ostream& ostr) const{
    if(*this){
        ostr << m_content << ": (" << m_volume << "cc/" << m_capacity << ")";
    }
    else{
        ostr << "****: (**cc/***)";
    }
    return ostr;
}

istream& Container::read(istream& istr) {
    int userInput = 0;
    
    if(*this){
        cout << "Add to ";
        cout << *this <<endl;
        
        userInput = getint(1, 220000, ">");
        
        cout << "Added " << (operator += (userInput)) << " CCs\n";
    }
    else{
        cout << "Broken Container, adding aborted! Press <ENTER> to continue....\n";
        istr.ignore(1000,'\n');
    }
    
    return istr;
}

istream& operator >>(istream& istr, Container& newContainer){
    newContainer.read(istr);
    return istr;
}

ostream& operator <<(ostream& ostr, const Container& newContainer) {
    
    return newContainer.print(ostr);
    
}

}
