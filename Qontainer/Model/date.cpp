#include "date.h"

Date::Date() : day(0), month(0), year(0) {}

Date::Date(unsigned int day, unsigned int month, unsigned int year) : day(day), month(month), year(year) {}

Date::Date(std::string date) {

}

Date::operator std::string() const {
    return (((std::to_string(day) += "/") += std::to_string(month)) += "/") += std::to_string(year);
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

bool Date::isValid() {

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
            if (day < date.day)
                return true;
            else
                return false;
        }
    }
}
