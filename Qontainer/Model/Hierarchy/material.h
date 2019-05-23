#ifndef MATERIAL_H
#define MATERIAL_H

#include "date.h"

#include <string>

class Material {
private:
    std::string author;
    std::string title;
    std::string realization_place;
    date realization_date;
    std::string photo;

    unsigned int sector;

    bool proprietary;
    bool damaged;
    bool available;

    unsigned int restorations;
    unsigned int loans;

    float income_expenses;

    static float base_restoration_cost;
    static float base_loans_proceeds;
public:
    Material();
    Material(std::string = "Sconoscituo", std::string = "Sconosciuto", std::string = "Sconosciuto", date = "0/0/0");
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

    void setAuthor(const std::string &);
    void setTitle(const std::string &);
    void setPlace(const std::string &);
    void setDate(const date &);
    void setPhoto(const std::string &);
    void setSector(unsigned int);
    void setProprietary(bool);
    void setDamaged(bool);
    void setAvailable(bool);
    void setRestorations(unsigned int);
    void setLoans(unsigned int);
    void setIncomeExpenses(float);

    virtual clone() const = 0;
    virtual getType() const = 0;

    // virtual methods to calculate value and restoration_cost
};

#endif // MATERIAL_H
