#include "1-date-class.hpp"


DateClass::DateClass(int day, int month, int year): m_day{day}, m_month{month}, m_year{year}, m_century{21}
{
}

DateClass::~DateClass()
{
    std::cout << "Good bye!!!" << std::endl;
}

void DateClass::set_date(int day, int month, int year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

void DateClass::print() const
{
    std::cout << m_day << "-" << m_month << "-" << m_year << std::endl;
}

void DateClass::copy(const DateClass &d) 
{
    m_day = d.m_day;
    m_month = d.m_month;
    m_year = d.m_year;
}