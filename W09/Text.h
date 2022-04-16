#ifndef TEXT_H
#define TEXT_H
#include <iostream>

using namespace std;
namespace sdds {

class Text{
    char* m_content;
    void setEmpty();
    
protected:
    const char& operator[](int index)const;
    
public:
    Text();
    Text(const char* newContent);
    Text(const Text& newText);
    Text& operator=(const Text& newText);
    ~Text();
    int getFileLength(std::istream& is);
    void read(std::istream &istr);
    virtual ostream& write(ostream& ostr) const;
};

istream& operator >>(istream& istr, Text& newText);
ostream& operator <<(ostream& ostr, const Text& newText);

}

#endif
