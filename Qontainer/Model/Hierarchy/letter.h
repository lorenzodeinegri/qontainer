#ifndef LETTER_H
#define LETTER_H

#include "literarywork.h"

class Letter : public LiteraryWork {
private:
    std::string addressee;

    static float letter_restoration_overcharge;
    static float letter_loan_overcharge;

protected:
    virtual float calculateRestorationCost() const override;
    virtual float calculateLoanProceed() const override;

public:
    explicit Letter(unsigned int = 0,
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
                    const date & = std::string("01/01/0100"),
                    const std::string & = ":/Photos/photoNotAvailable.jpeg",
                    unsigned int = 0,
                    unsigned int = 0,
                    float = 0.0f,
                    float = 0.0f);

    std::string getAddressee() const;

    void setAddressee(const std::string & = "Sconosciuto");

    virtual Letter * clone() const override;
    virtual std::string getType() const override;
    virtual std::string getInfo() const override;
    virtual float calculateValue() const override;
};

#endif // LETTER_H
