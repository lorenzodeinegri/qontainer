#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "literarywork.h"

class Act : public LiteraryWork {
private:
    std::string object;

    static float document_restoration_overcharge;
    static float document_loan_overcharge;

protected:
    virtual float calculateRestorationCost() const override;
    virtual float calculateLoanProceed() const override;

public:
    explicit Act(unsigned int = 0,
                 float = 0.0f,
                 bool = false,
                 bool = false,
                 bool = true,
                 const std::string & = "Sconosciuto",
                 bool = true,
                 bool = true,
                 const std::string & = "Sconosciuta",
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

    std::string getObject() const;

    void setObject(const std::string & = "Sconosciuto");

    virtual Act * clone() const override;
    virtual std::string getType() const override;
    virtual std::string getInfo() const override;
    virtual float calculateValue() const override;
};

#endif // DOCUMENT_H
