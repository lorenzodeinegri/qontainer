#include "artwork.h"

float ArtWork::artwork_restoration_overcharge = 3000.0f;

float ArtWork::artwork_loan_overcharge = 5000.0f;

float ArtWork::calculateRestorationCost() const {
    return (artwork_restoration_overcharge + Material::calculateRestorationCost()) * 1.3f;
}

float ArtWork::calculateLoanProceed() const {
    return (artwork_loan_overcharge + Material::calculateLoanProceed()) * 1.5f;
}

ArtWork::ArtWork(unsigned int sector,
                 float base_value,
                 bool proprietary,
                 bool damaged,
                 bool available,
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
    material(material),
    technique(technique),
    art_movement(art_movement),
    subject(subject) {}

std::string ArtWork::getMaterial() const {
    return material;
}

std::string ArtWork::getTechnique() const {
    return technique;
}

std::string ArtWork::getArtMovement() const {
    return art_movement;
}

std::string ArtWork::getSubject() const {
    return subject;
}

void ArtWork::setMaterial(const std::string & material) {
    this->material = material;
}

void ArtWork::setTechnique(const std::string & technique) {
    this->technique = technique;
}

void ArtWork::setArtMovement(const std::string & movement) {
    this->art_movement = movement;
}

void ArtWork::setSubject(const std::string & subject) {
    this->subject = subject;
}

std::string ArtWork::getMaterialType() const {
    return std::string("Opera d'arte");
}

std::string ArtWork::getInfo() const {
    std::string info("");
    info += Material::getInfo();
    info += ("\nMateriale: " + material);
    info += ("\nTecnica: " + technique);
    info += ("\nMovimento artistico: " + art_movement);
    info += ("\nSoggetto: " + subject);
    return info;
}

float ArtWork::calculateValue() const {
    float multiplier = 1.0f;
    multiplier += subject != "Sconosciuto" ? 0.1f : -0.1f;
    multiplier += art_movement != "Sconosciuto" ? 0.1f : -0.1f;
    return Material::calculateValue() * multiplier;
}
