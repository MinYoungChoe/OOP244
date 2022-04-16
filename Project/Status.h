#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

namespace sdds {

class Status{
    
    char* m_description; //description of status.
    int optionalStatusCode;
    
    void allocateAndCopy(const char* newDescription);
    void setEmpty();
    
public:
    Status& clear();
    Status();
    Status(const char* description);
    Status(const Status& otherStatus);
    Status& operator =(const Status& otherStatus);
    Status& operator=(int code);
    Status& operator=(const char* mess);
    ~Status();
    operator int() const;
    operator const char*() const;
    operator bool() const;
    
};
std::ostream& operator <<(std::ostream& ostr, const Status& otherStaus);


}
#endif // !SDDS_STATUS_H
