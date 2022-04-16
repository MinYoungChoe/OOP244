#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "Status.h"

namespace sdds {

const int maximumYearValue = 2030;

class Date{
    int m_year;
    int m_month;
    int m_day;
    Status State;
    bool Formatted;
    bool validDate();
    int uniqueInt()const;
    
public:
    Date& formatted(bool newFormat);
    const Status& state();
    Date();
    Date(int newYear, int newMonth, int newDay);
    operator bool() const;
    bool operator ==(const Date& right);
    bool operator !=(const Date& right);
    bool operator <(const Date& right);
    bool operator >(const Date& right);
    bool operator <=(const Date& right);
    bool operator >=(const Date& right);
    std::ostream& write(std::ostream& ostr) const;
    std::istream& read(std::istream& istr);
};

std::ostream& operator <<(std::ostream& ostr, const Date& otherDate);
std::istream& operator >>(std::istream& istr, Date& otherDate);

}
#endif // !SDDS_DATE_H
