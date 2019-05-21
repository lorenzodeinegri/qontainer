#ifndef DATA_H
#define DATA_H

#include <string>

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date();
    Date(unsigned int, unsigned int, unsigned int);
    Date(const std::string &);

    operator std::string() const;

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;

    void setDay(unsigned int);
    void setMonth(unsigned int);
    void setYear(unsigned int);

    bool isLeapYear() const;
    bool isValid() const;

    bool operator ==(const Date &) const;
    bool operator !=(const Date &) const;
    bool operator >=(const Date &) const;
    bool operator <=(const Date &) const;
    bool operator >(const Date &) const;
    bool operator <(const Date &) const;
};

#endif // DATA_H
