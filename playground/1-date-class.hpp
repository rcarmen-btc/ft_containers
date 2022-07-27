// date class header
#ifndef _DATECLASS_
#define _DATECLASS_
#include <iosfwd>
#include <iostream>

class DateClass
{
    int m_day;
    int m_month;
    int m_year;
    const int m_century;

public:

    DateClass(int day=0, int month=0, int year=0);

    ~DateClass();

    void set_date(int day, int month, int year);

    void print() const;

    void copy(const DateClass &d); 

};
    
#endif /* _DATECLASS_ */

