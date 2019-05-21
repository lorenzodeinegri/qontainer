#ifndef DATA_H
#define DATA_H

#include <string>

class date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    date();
    date(unsigned int, unsigned int, unsigned int);
    date(const std::string &);

    operator std::string() const;

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;

    void setDay(unsigned int);
    void setMonth(unsigned int);
    void setYear(unsigned int);

    bool isLeapYear() const;
    bool isValid() const;

    bool operator ==(const date &) const;
    bool operator !=(const date &) const;
    bool operator >=(const date &) const;
    bool operator <=(const date &) const;
    bool operator >(const date &) const;
    bool operator <(const date &) const;
};

#endif // DATA_H
