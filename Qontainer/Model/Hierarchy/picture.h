#ifndef PICTURE_H
#define PICTURE_H

#include "artwork.h"

class Picture : public ArtWork {
private:
    bool photography;

    static float picture_restoration_overcharge;
    static float picture_loan_overcharge;

protected:
    virtual float calculateRestorationCost() const override;
    virtual float calculateLoanProceed() const override;

public:
    explicit Picture(unsigned int = 0,
                     float = 0.0f,
                     bool = false,
                     bool = false,
                     bool = true,
                     bool = false,
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

    bool isPhotography() const;

    void setPhotography(bool = false);

    virtual Picture * clone() const override;
    virtual std::string getType() const override;
    virtual std::string getInfo() const override;
    virtual float calculateValue() const override;
};

#endif // PICTURE_H
