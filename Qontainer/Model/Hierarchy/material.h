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

    unsigned int sector;

    bool damaged;
    bool proprietary;
    bool available;

    unsigned int restorations;
    unsigned int loans;

    float outgoings; // TODO

    static float base_restoration_cost;
    static float base_loans_proceeds;
public:
    Material();
    // virtual methods to calculate value and restoration_cost
};

#endif // MATERIAL_H
