#ifndef INTERACT_H
#define INTERACT_H

#include "searchcombobox.h"
#include "list.h"

#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QRadioButton>
#include <QLineEdit>
#include <QDateEdit>
#include <QLabel>
#include <QModelIndexList>
#include <QValidator>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Interact : public QWidget {
    Q_OBJECT

private:
    List * list;

    SearchComboBox * searchComboBox;
    QLineEdit * searchEdit;

    QLabel * first;
    QLabel * last;

    QDateEdit * firstDate;
    QDateEdit * lastDate;

    QLineEdit * firstFloat;
    QLineEdit * lastFloat;

    QLineEdit * firstInteger;
    QLineEdit * lastInteger;

    QRadioButton * trueRadio;
    QRadioButton * falseRadio;


    void setLabelsVisibility(bool visibility) const;
    void setDatesVisibility(bool visibility) const;
    void setFloatsVisibility(bool visibility) const;
    void setIntegersVisibility(bool visibility) const;
    void setBoolsVisibility(bool visibility) const;

    void hideAll() const;
    void resetAll() const;

    void setBoolsLabels(const QString &) const;

private slots:
    void search(const QString &);
    void searchRegularExpressions(const QString &) const;
    void searchDates() const;
    void searchFloats() const;
    void searchIntegers() const;
    void searchBools() const;

    void details() const;
    void modifies() const;

    void restore() const;
    void lend() const;

    void calculateValue() const;
    void calculateProfit() const;
    void calculateIncome() const;
    void calculateExpense() const;

    void calculateTotalValue() const;
    void calculateTotalProfit() const;
    void calculateTotalIncome() const;
    void calculateTotalExpense() const;

    void deletes() const;

    void reset() const;

public:
    explicit Interact(List *, QWidget * = nullptr);

signals:
    void searchRegularExpressions(const QString &, const QString &) const;
    void searchDates(const QDate &, const QDate &, const QString &) const;
    void searchFloats(float, float, const QString &) const;
    void searchIntegers(unsigned int, unsigned int, const QString &) const;
    void searchBools(bool, const QString &) const;

    void details(const QModelIndex &) const;
    void modifies(const QModelIndex &) const;

    void restore(const QModelIndex &) const;
    void lend(const QModelIndex &) const;

    void calculateValue(const QModelIndex &) const;
    void calculateProfit(const QModelIndex &) const;
    void calculateIncome(const QModelIndex &) const;
    void calculateExpense(const QModelIndex &) const;

    void calculateTotalValue(const QModelIndexList &) const;
    void calculateTotalProfit(const QModelIndexList &) const;
    void calculateTotalIncome(const QModelIndexList &) const;
    void calculateTotalExpense(const QModelIndexList &) const;

    void deletes(const QModelIndex &) const;
};

#endif // INTERACT_H
