#include "act.h"

float Act::document_restoration_overcharge = 2000.0f;

float Act::document_loan_overcharge = 1500.0f;

float Act::calculateRestorationCost() const {
    return (document_restoration_overcharge + LiteraryWork::calculateRestorationCost()) * (isDamaged() ? 1.5f : 0.8f);
}

float Act::calculateLoanProceed() const {
    return (document_loan_overcharge + LiteraryWork::calculateLoanProceed()) * (isProprietary() ? 1.3f : 0.85f);
}

Act::Act(unsigned int sector,
         float base_value,
         bool proprietary,
         bool damaged,
         bool available,
         const std::string & object,
         bool complete,
         bool handwritten,
         const std::string & language,
         const std::string & style,
         const std::string & author,
         const std::string & title,
         const std::string & realization_place,
         const date & realization_date,
         const std::string & photo,
         unsigned int restorations,
         unsigned int loans,
         float income,
         float expense) :
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
                 photo,
                 restorations,
                 loans,
                 income,
                 expense),
    object(object) {}

std::string Act::getObject() const {
    return object;
}

void Act::setObject(const std::string & object) {
    this->object = object;
}

Act * Act::clone() const {
    return new Act(*this);
}

std::string Act::getType() const {
    return std::string("Atto");
}

std::string Act::getInfo() const {
    std::string info("Atto:");
    info += LiteraryWork::getInfo();
    info += ("\nOggetto: " + object);
    return info;
}

float Act::calculateValue() const {
    float multiplier = 1.0f;
    multiplier += object != "Sconosciuto" ? 0.1f : -0.5f;
    multiplier += !isDamaged() ? 0.2f : -0.4f;
    return LiteraryWork::calculateValue() * multiplier;
}
