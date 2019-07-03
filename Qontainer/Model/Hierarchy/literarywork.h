#ifndef LITERARYWORK_H
#define LITERARYWORK_H

#include "material.h"

class LiteraryWork : public Material {
private:
    bool complete;
    bool handwritten;

    std::string language;
    std::string style;

    static float literarywork_restoration_overcharge;
    static float literarywork_loan_overcharge;

protected:
    virtual float calculateRestorationCost() const override;
    virtual float calculateLoanProceed() const override;

public:
    explicit LiteraryWork(unsigned int = 0,
                          float = 0.0f,
                          bool = false,
                          bool = false,
                          bool = true,
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

    bool isComplete() const;
    bool isHandwritten() const;
    std::string getLanguage() const;
    std::string getStyle() const;

    void setComplete(bool = true);
    void setHandwritten(bool = true);
    void setLanguage(const std::string & = "Sconosciuta");
    void setStyle(const std::string & = "Sconosciuto");

    virtual std::string getMaterialType() const final override;
    virtual std::string getInfo() const override;
    virtual float calculateValue() const override;
};

#endif // LITERARYWORK_H
