#include "picture.h"

float Picture::picture_restoration_overcharge = 4500.0f;

float Picture::picture_loan_overcharge = 2500.0f;

float Picture::calculateRestorationCost() const {
    float multiplier = 1.0f;
    multiplier += isDamaged() ? 0.3f : -0.4f;
    return (picture_restoration_overcharge + ArtWork::calculateRestorationCost()) * multiplier;
}

float Picture::calculateLoanProceed() const {
    float multiplier = 1.0f;
    multiplier += isProprietary() ? 0.2f : -0.2f;
    return (picture_loan_overcharge + ArtWork::calculateLoanProceed()) * multiplier;
}

Picture::Picture(unsigned int sector,
                 float base_value,
                 bool proprietary,
                 bool damaged,
                 bool available,
                 bool photography,
                 const std::string & material,
                 const std::string & technique,
                 const std::string & art_movement,
                 const std::string & subject,
                 const std::string & author,
                 const std::string & title,
                 const std::string & realization_place,
                 const date & realization_date,
                 const std::string & photo) :
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
            photo),
    photography(photography) {}

bool Picture::isPhotography() const {
    return photography;
}

void Picture::setPhotography(bool photography) {
    this->photography = photography;
}

Picture * Picture::clone() const {
    return new Picture(*this);
}

std::string Picture::getType() const {
    return std::string("Dipinto");
}

std::string Picture::getInfo() const {
    std::string info("Dipinto:");
    info += ("\nFotografia: " + std::string(photography ? "Si" : "No"));
    info += ArtWork::getInfo();
    return info;
}

float Picture::calculateValue() const {
    float multiplier = 1.0f;
    multiplier += !photography ? 0.0f : -0.4f;
    multiplier += !isDamaged() ? 0.2f : -0.2f;
    return ArtWork::calculateValue() * multiplier;
}
