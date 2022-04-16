#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

namespace sdds {

class Container{
    char m_content[51];
    int m_capacity;
    int m_volume;
    
protected:
    void copy(const char* newContent, int &newCapacity, int newVolume);

    void setEmpty();
    int capacity() const;
    int volume() const;
    
public:

    Container();
    Container(const char* newContent, int newCapacity);
    Container(const char* newContent, int newCapacity, int newVolume);
    int operator +=(int addVolume);
    int operator -=(int subtract);
    operator bool() const;
    void clear(int newCapacity, const char* newContent);
    std::ostream& print(std::ostream& ostr) const;
    std::istream& read(std::istream& istr);

};

int getint(const char* prompt) ;
int getint(int min, int max, const char* prompt=nullptr, const char* errMes=nullptr);

std::istream& operator >>(std::istream& istr, Container& newContainer);
std::ostream& operator <<(std::ostream& ostr, const Container& newContainer);

}
 #endif //SDDS_CONTAINER_H
