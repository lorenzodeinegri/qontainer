#include "model.h"

unsigned int Model::count() const {
    return container.size();
}

void Model::add(Material * material) {
    container.push_back(DeepPointer<Material>(material));
}

void Model::remove(unsigned int index) {
    container.erase(container.begin() + static_cast<int>(index));
}

DeepPointer<Material> & Model::operator [](unsigned int index) {
    return container[index];
}

Material * Model::get(unsigned int index) const {
    return container[index].operator->();
}

void Model::loadFile(const std::string & filePath) {
    fileHandler handler(filePath);
    container = handler.read();
}

void Model::saveFile(const std::string & filePath) const {
    fileHandler handler(filePath);
    handler.write(container);
}

float Model::calculateValue(unsigned int index) const {
    return container[index]->calculateValue();
}

float Model::calculateProfit(unsigned int index) const {
    return container[index]->calculateProfit();
}

float Model::calculateTotalValue() const {
    float total = 0.0f;
    for (Container<DeepPointer<Material>>::const_iterator c_it = container.cbegin() ; c_it != container.cend() ; ++c_it)
        total += c_it->operator*().calculateValue();
    return total;
}

float Model::calculateTotalProfit() const {
    float total = 0.0f;
    for (Container<DeepPointer<Material>>::const_iterator c_it = container.cbegin() ; c_it != container.cend() ; ++c_it)
        total += c_it->operator*().calculateProfit();
    return total;
}

float Model::calculateTotalIncome() const {
    float total = 0.0f;
    for (Container<DeepPointer<Material>>::const_iterator c_it = container.cbegin() ; c_it != container.cend() ; ++c_it)
        total += c_it->operator*().getIncome();
    return total;
}

float Model::calculateTotalExpense() const {
    float total = 0.0f;
    for (Container<DeepPointer<Material>>::const_iterator c_it = container.cbegin() ; c_it != container.cend() ; ++c_it)
        total += c_it->operator*().getExpense();
    return total;
}

bool Model::restore(unsigned int index) {
    return container[index]->restore();
}

bool Model::lend(unsigned int index) {
    return container[index]->lend();
}
