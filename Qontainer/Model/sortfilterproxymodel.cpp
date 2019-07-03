#include "sortfilterproxymodel.h"

bool SortFilterProxyModel::filterAcceptsRow(int row_index, const QModelIndex &) const {
    QString filter = searchFilters->currentText();
    if (filter == "Data") {
        if (begin_date.isValid() && end_date.isValid() && begin_date <= end_date)
            return static_cast<ListModelAdapter *>(sourceModel())->findDateMatch(static_cast<unsigned int>(row_index),
                                                                                 begin_date,
                                                                                 end_date,
                                                                                 filter);
        else
            return false;
    }
    else if (filter == "Valore Base" || filter == "Entrate" || filter == "Uscite") {
        if (begin_float <= end_float)
            return static_cast<ListModelAdapter *>(sourceModel())->findFloatMatch(static_cast<unsigned int>(row_index), begin_float, end_float, filter);
        else
            return false;
    }
    else if (filter == "Restauri" || filter == "Prestiti") {
        if (begin_integer <= end_integer)
            return static_cast<ListModelAdapter *>(sourceModel())->findIntegerMatch(static_cast<unsigned int>(row_index), begin_integer, end_integer, filter);
        else
            return false;
    }
    else if (filter == "Proprieta" || filter == "Stato" || filter == "Disponibilita" || filter == "Testo" || filter == "Scrittura" || filter == "Formato")
        return static_cast<ListModelAdapter *>(sourceModel())->findBoolMatch(static_cast<unsigned int>(row_index), is_true, filter);
    else
        return static_cast<ListModelAdapter *>(sourceModel())->findMatch(static_cast<unsigned int>(row_index), filterRegExp(), filter);
}

SortFilterProxyModel::SortFilterProxyModel(const QComboBox * searchFilters, QObject * parent) :
    QSortFilterProxyModel(parent),
    searchFilters(searchFilters) {}

bool SortFilterProxyModel::insertRows(int begin, int count, const QModelIndex & parent) {
    bool result = sourceModel()->insertRows(begin, count, parent);
    invalidateFilter();
    return result;
}

void SortFilterProxyModel::setDateValues(const date & begin_date, const date & end_date) {
    this->begin_date = begin_date;
    this->end_date = end_date;
    invalidateFilter();
}

void SortFilterProxyModel::setFloatValues(float begin_float, float end_float) {
    this->begin_float = begin_float;
    this->end_float = end_float;
    invalidateFilter();
}

void SortFilterProxyModel::setIntegerValues(unsigned int begin_integer, unsigned int end_integer) {
    this->begin_integer = begin_integer;
    this->end_integer = end_integer;
    invalidateFilter();
}

void SortFilterProxyModel::setBoolValue(bool is_true) {
    this->is_true = is_true;
    invalidateFilter();
}

void SortFilterProxyModel::showDisplay(const QModelIndex & filterIndex) const {
    static_cast<ListModelAdapter *>(sourceModel())->showDisplay(mapToSource(filterIndex));
}

void SortFilterProxyModel::showModify(const QModelIndex & filterIndex) const {
    static_cast<ListModelAdapter *>(sourceModel())->showModify(mapToSource(filterIndex));
}

bool SortFilterProxyModel::restore(const QModelIndex & filterIndex) const {
    return static_cast<ListModelAdapter *>(sourceModel())->restore(mapToSource(filterIndex));
}

bool SortFilterProxyModel::lend(const QModelIndex & filterIndex) const {
    return static_cast<ListModelAdapter *>(sourceModel())->lend(mapToSource(filterIndex));
}

float SortFilterProxyModel::calculateValue(const QModelIndex & filterIndex) const {
    return static_cast<ListModelAdapter *>(sourceModel())->calculateValue(mapToSource(filterIndex));
}

float SortFilterProxyModel::calculateProfit(const QModelIndex & filterIndex) const {
    return static_cast<ListModelAdapter *>(sourceModel())->calculateProfit(mapToSource(filterIndex));
}

float SortFilterProxyModel::calculateTotalValue() const {
    ListModelAdapter * modelAdapter = static_cast<ListModelAdapter *>(sourceModel());
    if (rowCount() == modelAdapter->rowCount()) {
        return modelAdapter->calculateTotalValue();
    }
    else {
        float value = 0.0f;
        for (int i = 0 ; i < rowCount() ; ++i)
            value += calculateValue(index(i, 0));
        return value;
    }
}

float SortFilterProxyModel::calculateTotalProfit() const {
    ListModelAdapter * modelAdapter = static_cast<ListModelAdapter *>(sourceModel());
    if (rowCount() == modelAdapter->rowCount()) {
        return modelAdapter->calculateTotalProfit();
    }
    else {
        float profit = 0.0f;
        for (int i = 0 ; i < rowCount() ; ++i)
            profit += calculateProfit(index(i, 0));
        return profit;
    }
}

float SortFilterProxyModel::calculateTotalIncome() const {
    ListModelAdapter * modelAdapter = static_cast<ListModelAdapter *>(sourceModel());
    if (rowCount() == modelAdapter->rowCount()) {
        return modelAdapter->calculateTotalIncome();
    }
    else {
        float income = 0.0f;
        for (int i = 0 ; i < rowCount() ; ++i)
            income += modelAdapter->calculateIncome(mapToSource(index(i, 0)));
        return income;
    }
}

float SortFilterProxyModel::calculateTotalExpense() const {
    ListModelAdapter * modelAdapter = static_cast<ListModelAdapter *>(sourceModel());
    if (rowCount() == modelAdapter->rowCount()) {
        return modelAdapter->calculateTotalExpense();
    }
    else {
        float expense = 0.0f;
        for (int i = 0 ; i < rowCount() ; ++i)
            expense += modelAdapter->calculateExpense(mapToSource(index(i, 0)));
        return expense;
    }
}
