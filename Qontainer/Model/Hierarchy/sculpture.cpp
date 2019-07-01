#include "sculpture.h"

float Sculpture::sculpture_restoration_overcharge = 2500.0f;

float Sculpture::sculpture_loan_overcharge = 3500.0f;

float Sculpture::calculateRestorationCost() const {
    return (sculpture_restoration_overcharge + ArtWork::calculateRestorationCost()) * (isDamaged() ? 1.5f : 0.8f);
}

float Sculpture::calculateLoanProceed() const {
    return (sculpture_loan_overcharge + ArtWork::calculateLoanProceed()) * (isProprietary() ? 1.4f : 0.9f);
}

Sculpture::Sculpture(unsigned int sector,
                     float base_value,
                     bool proprietary,
                     bool damaged,
                     bool available,
                     const std::string & shape,
                     const std::string & material,
                     const std::string & technique,
                     const std::string & art_movement,
                     const std::string & subject,
                     const std::string & author,
                     const std::string & title,
                     const std::string & realization_place,
                     const date & realization_date,
                     const std::string & photo,
                     unsigned int restorations,
                     unsigned int loans,
                     float income,
                     float expense) :
    ArtWork(sector,
            base_value,
            proprietary,
            damaged,
            available,
            material,
            technique,
            art_movement,
            subject,
            author,
            title,
            realization_place,
            realization_date,
            photo,
            restorations,
            loans,
            income,
            expense),
    shape(shape) {}

std::string Sculpture::getShape() const {
    return shape;
}

void Sculpture::setShape(const std::string & shape) {
    this->shape = shape;
}

Sculpture * Sculpture::clone() const {
    return new Sculpture(*this);
}

std::string Sculpture::getType() const {
    return std::string("Scultura");
}

std::string Sculpture::getInfo() const {
    std::string info("Scultura:");
    info += ("\nForma: " + shape);
    info += ArtWork::getInfo();
    return info;
}

float Sculpture::calculateValue() const {
    float multiplier = 1.0f;
    multiplier += shape != "Sconosciuta" ? 0.1f : -0.1f;
    multiplier += !isDamaged() ? 0.3f : -0.3f;
    return ArtWork::calculateValue() * multiplier;
}
