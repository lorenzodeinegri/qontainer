#include "date.h"

Date::Date() : day(1), month(1), year(0) {}

Date::Date(unsigned int day, unsigned int month, unsigned int year) : day(day), month(month), year(year) {}

Date::Date(const std::string & date) : day(1), month(1), year(0) {
    try {
        day = std::stoul(date.substr(0, 2));
        month = std::stoul(date.substr(3, 2));
        year = std::stoul(date.substr(6));
    }
    catch (...) {}
}

Date::operator std::string() const {
    return std::to_string(day).length() >= 2 ? std::to_string(day) : "0" + std::to_string(day) + "/" + std::to_string(month).length() >= 2 ? std::to_string(month) : "0" + std::to_string(month) + "/" + std::to_string(year);
}

unsigned int Date::getDay() const {
    return day;
}

unsigned int Date::getMonth() const {
    return month;
}

unsigned int Date::getYear() const {
    return year;
}

void Date::setDay(unsigned int day) {
    this->day = day;
}

void Date::setMonth(unsigned int month) {
    this->month = month;
}

void Date::setYear(unsigned int year) {
    this->year = year;
}

bool Date::isLeapYear() const {
    return (year % 4 && !(year % 100)) || year % 400;
}

bool Date::isValid() const {
    switch (month) {
        case 2:
            return isLeapYear() ? 1 <= day && day <= 29 : 1 <= day && day <= 28;
        case 4: case 6: case 9: case 11:
            return 1 <= day && day <= 30;
        default:
            return 1 <= month && month <= 12 && 1 <= day && day <= 31;
    }
}

bool Date::operator ==(const Date & date) const {
    return year == date.year && month == date.month && day == date.day;
}

bool Date::operator !=(const Date & date) const {
    return !(*this == date);
}

bool Date::operator >=(const Date & date) const {
    return *this > date || *this == date;
}

bool Date::operator <=(const Date & date) const {
    return *this < date || *this == date;
}

bool Date::operator >(const Date & date) const {
    return !(*this <= date);
}

bool Date::operator <(const Date & date) const {
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
