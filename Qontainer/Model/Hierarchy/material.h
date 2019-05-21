#ifndef MATERIAL_H
#define MATERIAL_H

#include "date.h"

#include <string>

class Material {
private:
    std::string author;
    std::string title;
    date realization_date;

    bool is_private;

    unsigned int restorations;
    unsigned int loans;

    float value;
    float outgoings;

    static float restoration_cost;
    static float loans_proceeds;
public:
    Material();
};

#endif // MATERIAL_H
