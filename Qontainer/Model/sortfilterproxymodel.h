#ifndef SORTFILTERPROXYMODEL_H
#define SORTFILTERPROXYMODEL_H

#include "searchcombobox.h"
#include "listmodeladapter.h"
#include "date.h"

#include <QSortFilterProxyModel>

class SortFilterProxyModel : public QSortFilterProxyModel {
private:
    const SearchComboBox * searchFilters;

    date begin_date;
    date end_date;

    float begin_float;
    float end_float;

    unsigned int begin_integer;
    unsigned int end_integer;

    bool is_true;

protected:
    bool filterAcceptsRow(int, const QModelIndex &) const override;

public:
    explicit SortFilterProxyModel(const SearchComboBox * = nullptr, QObject * = nullptr);

    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;

    void setDateValues(const date &, const date &);
    void setFloatValues(float, float);
    void setIntegerValues(unsigned int, unsigned int);
    void setBoolValue(bool);

    void showDisplay(const QModelIndex &) const;
    void showModify(const QModelIndex &) const;

    bool restore(const QModelIndex &) const;
    bool lend(const QModelIndex &) const;

    float calculateValue(const QModelIndex &) const;
    float calculateProfit(const QModelIndex &) const;
    float calculateIncome(const QModelIndex &) const;
    float calculateExpense(const QModelIndex &) const;

    float calculateTotalValue() const;
    float calculateTotalProfit() const;
    float calculateTotalIncome() const;
    float calculateTotalExpense() const;
};

#endif // SORTFILTERPROXYMODEL_H
