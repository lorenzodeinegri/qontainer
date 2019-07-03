#ifndef MODEL_H
#define MODEL_H

#include "container.h"
#include "deeppointer.h"
#include "material.h"
#include "filehandler.h"

class Model {
private:
    Container<DeepPointer<Material>> container;

public:
    Model() = default;
    ~Model() = default;

    unsigned int count() const;

    void add(Material *);
    void remove(unsigned int);

    DeepPointer<Material> & operator [](unsigned int);
    Material * get(unsigned int) const;

    void loadFile(const std::string &);
    void saveFile(const std::string &) const;

    float calculateValue(unsigned int) const;
    float calculateProfit(unsigned int) const;

    float calculateTotalValue() const;
    float calculateTotalProfit() const;
    float calculateTotalIncome() const;
    float calculateTotalExpense() const;

    bool restore(unsigned int);
    bool lend(unsigned int);
};

#endif // MODEL_H
