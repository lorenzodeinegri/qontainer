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

    SearchComboBox * searchComboBox;


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
    void searchExpressions(const QString &) const;
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

    void deletes() const;

    void reset() const;

public:
    explicit Interact(List *, SearchComboBox *, QWidget * = nullptr);

    virtual QSize sizeHint() const override;

signals:
    void searchRegularExpressions(const QString &) const;
    void searchDates(const QDate &, const QDate &) const;
    void searchFloats(float, float) const;
    void searchIntegers(unsigned int, unsigned int) const;
    void searchBools(bool) const;

    void details(const QModelIndexList &) const;
    void modifies(const QModelIndexList &) const;

    void restore(const QModelIndexList &) const;
    void lend(const QModelIndexList &) const;

    void calculateValue(const QModelIndexList &) const;
    void calculateProfit(const QModelIndexList &) const;
    void calculateIncome(const QModelIndexList &) const;
    void calculateExpense(const QModelIndexList &) const;

    void calculateTotalValue() const;
    void calculateTotalProfit() const;
    void calculateTotalIncome() const;
    void calculateTotalExpense() const;

    void deletes(const QModelIndexList &) const;
};

#endif // INTERACT_H
