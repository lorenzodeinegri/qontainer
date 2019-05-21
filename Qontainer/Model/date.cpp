#include "date.h"

date::date() : day(1), month(1), year(0) {}

date::date(unsigned int day, unsigned int month, unsigned int year) : day(day), month(month), year(year) {}

date::date(const std::string & date) : day(1), month(1), year(0) {
    try {
        day = std::stoul(date.substr(0, 2));
        month = std::stoul(date.substr(3, 2));
        year = std::stoul(date.substr(6));
    }
    catch (...) {}
}

date::operator std::string() const {
    return std::to_string(day).length() >= 2 ? std::to_string(day) : "0" + std::to_string(day) + "/" + std::to_string(month).length() >= 2 ? std::to_string(month) : "0" + std::to_string(month) + "/" + std::to_string(year);
}

unsigned int date::getDay() const {
    return day;
}

unsigned int date::getMonth() const {
    return month;
}

unsigned int date::getYear() const {
    return year;
}

void date::setDay(unsigned int day) {
    this->day = day;
}

void date::setMonth(unsigned int month) {
    this->month = month;
}

void date::setYear(unsigned int year) {
    this->year = year;
}

bool date::isLeapYear() const {
    return (year % 4 && !(year % 100)) || year % 400;
}

bool date::isValid() const {
    switch (month) {
        case 2:
            return isLeapYear() ? 1 <= day && day <= 29 : 1 <= day && day <= 28;
        case 4: case 6: case 9: case 11:
            return 1 <= day && day <= 30;
        default:
            return 1 <= month && month <= 12 && 1 <= day && day <= 31;
    }
}

bool date::operator ==(const date & date) const {
    return year == date.year && month == date.month && day == date.day;
}

bool date::operator !=(const date & date) const {
    return !(*this == date);
}

bool date::operator >=(const date & date) const {
    return *this > date || *this == date;
}

bool date::operator <=(const date & date) const {
    return *this < date || *this == date;
}

bool date::operator >(const date & date) const {
    return !(*this <= date);
}

bool date::operator <(const date & date) const {
    if (year < date.year)
        return true;
    else if (year > date.year)
        return false;
    else {
        if (month < date.month)
            return true;
        else if (month > date.month)
            return false;
        else {
            return day < date.day;
        }
    }
}
