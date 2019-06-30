#ifndef MATERIAL_H
#define MATERIAL_H

#include "date.h"

#include <string>

class Material {
private:
    unsigned int sector;

    float base_value;

    bool proprietary;
    bool damaged;
    bool available;

    std::string author;
    std::string title;
    std::string realization_place;
    date realization_date;

    std::string photo;

    unsigned int restorations;
    unsigned int loans;

    float income_expenses;

    static float base_restoration_cost;
    static float base_loan_deposit;

protected:
    virtual float calculateRestorationCost() const;
    virtual float calculateLoanProceed() const;

public:
    Material(unsigned int = 0,
             float = 0.0f,
             bool = false,
             bool = false,
             bool = true,
             const std::string & = "Sconosciuto",
             const std::string & = "Sconosciuto",
             const std::string & = "Sconosciuto",
             const date & = std::string("00/00/0000"),
             const std::string & = ":/Photos/Photos/photoNotAvailable.jpeg");
    virtual ~Material() = default;

    std::string getAuthor() const;
    std::string getTitle() const;
    std::string getPlace() const;
    date getDate() const;
    std::string getPhoto() const;
    unsigned int getSector() const;
    bool isProprietary() const;
    bool isDamaged() const;
    bool isAvailable() const;
    unsigned int getRestorations() const;
    unsigned int getLoans() const;
    float getIncomeExpenses() const;
    float getBaseValue() const;

    void setAuthor(const std::string & = "Sconosciuto");
    void setTitle(const std::string & = "Sconosciuto");
    void setPlace(const std::string & = "Sconosciuto");
    void setDate(const date & = std::string("00/00/0000"));
    void setPhoto(const std::string & = ":/Photos/Photos/photoNotAvailable.jpeg");
    void setSector(unsigned int = 0);
    void setProprietary(bool = true);
    void setDamaged(bool = true);
    void setAvailable(bool = true);
    void setRestorations(unsigned int = 0);
    void setLoans(unsigned int = 0);
    void setIncomeExpenses(float = 0.0f);
    void setBaseValue(float = 0.0f);

    virtual Material * clone() const = 0;
    virtual std::string getType() const = 0;
    virtual std::string getMaterialType() const = 0;
    virtual std::string getInfo() const;
    virtual float calculateValue() const;

    void restore();
    void lend();
};

#endif // MATERIAL_H
