#include "literarywork.h"

float LiteraryWork::literarywork_restoration_overcharge = 2000.0f;

float LiteraryWork::literarywork_loan_overcharge = 1000.0f;

float LiteraryWork::calculateRestorationCost() const {
    return (literarywork_restoration_overcharge + Material::calculateRestorationCost()) * 1.4f;
}

float LiteraryWork::calculateLoanProceed() const {
    return (literarywork_loan_overcharge + Material::calculateLoanProceed()) * 1.2f;
}

LiteraryWork::LiteraryWork(unsigned int sector,
                           float base_value,
                           bool proprietary,
                           bool damaged,
                           bool available,
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
    Material(sector,
             base_value,
             proprietary,
             damaged,
             available,
             author,
             title,
             realization_place,
             realization_date,
             photo,
             restorations,
             loans,
             income,
             expense),
    complete(complete),
    handwritten(handwritten),
    language(language),
    style(style) {}

bool LiteraryWork::isComplete() const {
    return complete;
}

bool LiteraryWork::isHandwritten() const {
    return handwritten;
}

std::string LiteraryWork::getLanguage() const {
    return language;
}

std::string LiteraryWork::getStyle() const {
    return style;
}

void LiteraryWork::setComplete(bool complete) {
    this->complete = complete;
}

void LiteraryWork::setHandwritten(bool handwritten) {
    this->handwritten = handwritten;
}

void LiteraryWork::setLanguage(const std::string & language) {
    this->language = language;
}

void LiteraryWork::setStyle(const std::string & style) {
    this->style = style;
}

std::string LiteraryWork::getMaterialType() const {
    return std::string("Opera letteraria");
}

std::string LiteraryWork::getInfo() const {
    std::string info("");
    info += Material::getInfo();
    info += ("\nCompleto: " + std::string(complete ? "Si" : "No"));
    info += ("\nScritto a mano: " + std::string(handwritten ? "Si" : "No"));
    info += ("\nLingua: " + language);
    info += ("\nStile: " + style);
    return info;
}

float LiteraryWork::calculateValue() const {
    float multiplier = 1.0f;
    multiplier += !complete ? -0.3f : 0.2f;
    multiplier += !handwritten ? 0.0f : 0.2f;
    return Material::calculateValue() * multiplier;
}
