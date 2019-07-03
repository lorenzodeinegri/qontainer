#ifndef ARTWORK_H
#define ARTWORK_H

#include "material.h"

class ArtWork : public Material {
private:
    std::string material;
    std::string technique;
    std::string art_movement;
    std::string subject;

    static float artwork_restoration_overcharge;
    static float artwork_loan_overcharge;

protected:
    virtual float calculateRestorationCost() const override;
    virtual float calculateLoanProceed() const override;

public:
    explicit ArtWork(unsigned int = 0,
                     float = 0.0f,
                     bool = false,
                     bool = false,
                     bool = true,
                     const std::string & = "Sconosciuto",
                     const std::string & = "Sconosciuta",
                     const std::string & = "Sconosciuto",
                     const std::string & = "Sconosciuto",
                     const std::string & = "Sconosciuto",
                     const std::string & = "Sconosciuto",
                     const std::string & = "Sconosciuto",
                     const date & = std::string("00/00/0000"),
                     const std::string & = ":/Photos/photoNotAvailable.jpeg",
                     unsigned int = 0,
                     unsigned int = 0,
                     float = 0.0f,
                     float = 0.0f);

    std::string getMaterial() const;
    std::string getTechnique() const;
    std::string getArtMovement() const;
    std::string getSubject() const;

    void setMaterial(const std::string & = "Sconosciuto");
    void setTechnique(const std::string & = "Sconosciuta");
    void setArtMovement(const std::string & = "Sconosciuto");
    void setSubject(const std::string & = "Sconosciuto");

    virtual std::string getMaterialType() const final override;
    virtual std::string getInfo() const override;
    virtual float calculateValue() const override;
};

#endif // ARTWORK_H
