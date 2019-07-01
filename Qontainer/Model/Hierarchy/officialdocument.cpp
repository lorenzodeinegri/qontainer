#include "officialdocument.h"

float OfficialDocument::document_restoration_overcharge = 2000.0f;

float OfficialDocument::document_loan_overcharge = 1500.0f;

float OfficialDocument::calculateRestorationCost() const {
    return (document_restoration_overcharge + LiteraryWork::calculateRestorationCost()) * (isDamaged() ? 1.5f : 0.8f);
}

float OfficialDocument::calculateLoanProceed() const {
    return (document_loan_overcharge + LiteraryWork::calculateLoanProceed()) * (isProprietary() ? 1.3f : 0.85f);
}

OfficialDocument::OfficialDocument(unsigned int sector,
                                   float base_value,
                                   bool proprietary,
                                   bool damaged,
                                   bool available,
                                   const std::string & typology,
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
    typology(typology) {}

std::string OfficialDocument::getTypology() const {
    return typology;
}

void OfficialDocument::setTypology(const std::string & typology) {
    this->typology = typology;
}

OfficialDocument * OfficialDocument::clone() const {
    return new OfficialDocument(*this);
}

std::string OfficialDocument::getType() const {
    return std::string("Documento ufficiale");
}

std::string OfficialDocument::getInfo() const {
    std::string info("Documento ufficiale:");
    info += ("\nTipologia: " + typology);
    info += LiteraryWork::getInfo();
    return info;
}

float OfficialDocument::calculateValue() const {
    float multiplier = 1.0f;
    multiplier += typology != "Sconosciuta" ? 0.1f : -0.5f;
    multiplier += !isDamaged() ? 0.2f : -0.4f;
    return LiteraryWork::calculateValue() * multiplier;
}
