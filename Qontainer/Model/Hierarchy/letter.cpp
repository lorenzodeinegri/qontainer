#include "letter.h"

float Letter::letter_restoration_overcharge = 2500.0f;

float Letter::letter_loan_overcharge = 1000.0f;

float Letter::calculateRestorationCost() const {
    return (letter_restoration_overcharge + LiteraryWork::calculateRestorationCost()) * (isDamaged() ? 1.4f : 0.9f);
}

float Letter::calculateLoanProceed() const {
    return (letter_loan_overcharge + LiteraryWork::calculateLoanProceed()) * (isProprietary() ? 1.5f : 1.0f);
}

Letter::Letter(unsigned int sector,
               float base_value,
               bool proprietary,
               bool damaged,
               bool available,
               const std::string & addressee,
               bool complete,
               bool handwritten,
               const std::string & language,
               const std::string & style,
               const std::string & author,
               const std::string & title,
               const std::string & realization_place,
               const date & realization_date,
               const std::string & photo) :
    LiteraryWork(sector,
                 base_value,
                 proprietary,
                 damaged,
                 available,
                 complete,
                 handwritten,
                 language,
                 style,
                 author,
                 title,
                 realization_place,
                 realization_date,
                 photo),
    addressee(addressee) {}

std::string Letter::getAddressee() const {
    return addressee;
}

void Letter::setAddressee(const std::string & addressee) {
    this->addressee = addressee;
}

Letter * Letter::clone() const {
    return new Letter(*this);
}

std::string Letter::getType() const {
    return std::string("Lettera");
}

std::string Letter::getInfo() const {
    std::string info("Lettera:");
    info += ("\nDestinatario: " + addressee);
    info += LiteraryWork::getInfo();
    return info;
}

float Letter::calculateValue() const {
    float multiplier = 1.0f;
    multiplier += !addressee.compare("Sconosciuto") ? 0.25f : -0.35f;
    multiplier += !isDamaged() ? 0.4f : -0.1f;
    return LiteraryWork::calculateValue() * multiplier;
}
