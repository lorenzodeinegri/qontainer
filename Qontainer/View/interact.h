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

private slots:
    void search(const QString &) const;
    void searchRegularExpressions(const QString &) const;
    void searchDates(const QDate &) const;
    void searchFloats(float) const;
    void searchIntegers(int) const;
    void searchBools(bool) const;

    void reset() const;

public:
    explicit Interact(List *, QWidget * = nullptr);

signals:
    void search(const QString &, const QString &) const;
    void searchDates(const QDate &, const QDate &, const QString &) const;
    void searchFloats(float, float, const QString &) const;
    void searchIntegers(int, int, const QString &) const;

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
};

#endif // INTERACT_H
