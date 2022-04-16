#ifndef SDDS_NAME_H
#define SDDS_NAME_H

using namespace std;
namespace sdds {

class Name{
    char* m_firstName{};
    char* m_middleName{};
    char* m_lastName{};
    bool m_short{};
    void setEmpty();
    void extractChar(istream& istr, char ch) const;
    void set(const char* newFirstName);
    void set(const char* newFirstName, const char* newLastName);
    void set(const char* newFirstName, const char* newMiddleName, const char* newLastName);
    
public:
    void setShort(bool m_value);
    Name();
    Name(const char* firstName);
    Name(const char* firstName, const char* lastName);
    Name(const char* firstName, const char* middleName, const char* lastName);
    Name(const Name& newName);
    ~Name();
    Name& operator=(const Name& newName);
    Name& operator+=(const char* adding);
    istream& read(istream& istr);
    ostream& display(ostream& ostr) const;
    operator bool() const;
};

istream& operator >>(istream& istr, Name& newName);
ostream& operator <<(ostream& ostr, const Name& newName);

}

#endif // !SDDS_NAME_H

