#include "material.h"

float Material::base_restoration_cost = 10000.0f;

float Material::base_loan_deposit = 5000.0f;

float Material::calculateRestorationCost() const {
    float multiplier = 1.0f;
    multiplier += restorations == 0 ? 0.5f : 0.0f;
    multiplier += restorations < 5 ? 0.0f : -0.3f;
    return base_restoration_cost * multiplier;
}

float Material::calculateLoanProceed() const {
    return base_loan_deposit * (loans == 0 ? 1.25f : 1.0f);
}

Material::Material(unsigned int sector,
                   float base_value,
                   bool proprietary,
                   bool damaged,
                   bool available,
                   const std::string & author,
                   const std::string & title,
                   const std::string & realization_place,
                   const date & realization_date,
                   const std::string & photo,
                   unsigned int restorations,
                   unsigned int loans,
                   float income,
                   float expense) :
    sector(sector),
    base_value(base_value),
    proprietary(proprietary),
    damaged(damaged),
    available(available),
    author(author),
    title(title),
    realization_place(realization_place),
    realization_date(realization_date),
    photo(photo),
    restorations(restorations),
    loans(loans),
    income(income),
    expense(expense) {}

std::string Material::getAuthor() const {
    return author;
}

std::string Material::getTitle() const {
    return title;
}

std::string Material::getPlace() const {
    return realization_place;
}

date Material::getDate() const {
    return realization_date;
}

std::string Material::getPhoto() const {
    return photo;
}

unsigned int Material::getSector() const {
    return sector;
}

bool Material::isProprietary() const {
    return proprietary;
}

bool Material::isDamaged() const {
    return damaged;
}

bool Material::isAvailable() const {
    return available;
}

unsigned int Material::getRestorations() const {
    return restorations;
}

unsigned int Material::getLoans() const {
    return loans;
}

float Material::getIncome() const {
    return income;
}

float Material::getExpense() const {
    return expense;
}

float Material::getBaseValue() const {
    return base_value;
}

void Material::setAuthor(const std::string & author) {
    this->author = author;
}

void Material::setTitle(const std::string & title) {
    this->title = title;
}

void Material::setPlace(const std::string & realization_place) {
    this->realization_place = realization_place;
}

void Material::setDate(const date & realization_date) {
    this->realization_date = realization_date;
}

void Material::setPhoto(const std::string & photo) {
    this->photo = photo;
}

void Material::setSector(unsigned int sector) {
    this->sector = sector;
}

void Material::setProprietary(bool proprietary) {
    this->proprietary = proprietary;
}

void Material::setDamaged(bool damaged) {
    this->damaged = damaged;
}

void Material::setAvailable(bool available) {
    this->available = available;
}

void Material::setRestorations(unsigned int restorations) {
    this->restorations = restorations;
}

void Material::setLoans(unsigned int loans) {
    this->loans = loans;
}

void Material::setIncome(float income) {
    this->income = income;
}

void Material::setExpense(float expense) {
    this->expense = expense;
}

void Material::setBaseValue(float base_value) {
    this->base_value = base_value;
}

std::string Material::getInfo() const {
    std::string info("");
    info += ("\nAutore: " + author);
    info += ("\nTitolo: " + title);
    info += ("\nData di realizzazione: " + std::string(realization_date));
    info += ("\nLuogo di realizzazione: " + realization_place);
    info += ("\nSettore: " + std::to_string(sector));
    info += ("\nDisponibile:" + std::string(available ? "Si" : "No"));
    info += ("\nPrivato: " + std::string(proprietary ? "Si" : "No"));
    info += ("\nDanneggiato: " + std::string(damaged ? "Si" : "No"));
    info += ("\nRestaurazioni: " + std::to_string(restorations));
    info += ("\nPrestiti: " + std::to_string(loans));
    info += ("\nValore di base: " + std::to_string(base_value));
    info += ("\nRicavi: " + std::to_string(income));
    info += ("\nSpese: " + std::to_string(expense));
    return info;
}

float Material::calculateValue() const {
    return !author.compare("Sconosciuto") ? base_value : base_value * 1.5f;
}

bool Material::restore() {
    if (available) {
        available = false;
        ++restorations;
        expense += calculateRestorationCost();
        return true;
    }
    else
        return false;
}

bool Material::lend() {
    if (available) {
        available = false;
        ++loans;
        income += calculateLoanProceed();
        return true;
    }
    else
        return false;
}

float Material::calculateProfit() {
    return income - expense;
}
