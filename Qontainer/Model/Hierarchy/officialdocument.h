#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "literarywork.h"

class OfficialDocument : public LiteraryWork {
private:
    std::string typology;

    static float document_restoration_overcharge;
    static float document_loan_overcharge;

protected:
    virtual float calculateRestorationCost() const override;
    virtual float calculateLoanProceed() const override;

public:
    OfficialDocument(unsigned int = 0,
                     float = 0.0f,
                     bool = false,
                     bool = false,
                     bool = true,
                     const std::string & = "Sconosciuta",
                     bool = true,
                     bool = true,
                     const std::string & = "Sconosciuta",
                     const std::string & = "Sconosciuto",
                     const std::string & = "Sconosciuto",
                     const std::string & = "Sconosciuto",
                     const std::string & = "Sconosciuto",
                     const date & = std::string("00/00/0000"),
                     const std::string & = ":/Photos/photoNotAvailable.jpeg");

    std::string getTypology() const;

    void setTypology(const std::string & = "Sconosciuta");

    virtual OfficialDocument * clone() const override;
    virtual std::string getType() const override;
    virtual std::string getInfo() const override;
    virtual float calculateValue() const override;
};

#endif // DOCUMENT_H
