#ifndef LISTMODELADAPTER_H
#define LISTMODELADAPTER_H

#include "model.h"
#include "date.h"
#include "details.h"
#include "modifies.h"

#include <QAbstractListModel>
#include <QBrush>
#include <QColor>

class ListModelAdapter : public QAbstractListModel {
private:
    Model * model;
    DeepPointer<Material> nextInsert;

public:
    explicit ListModelAdapter(QObject * = nullptr);
    ~ListModelAdapter() override;

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &, int = Qt::DisplayRole) const override;

    bool insertRows(int, int = 1, const QModelIndex & = QModelIndex()) override;
    bool removeRows(int, int = 1, const QModelIndex & = QModelIndex()) override;

    void setNextInsert(Material *);

    void showDisplay(const QModelIndex &) const;
    void showModify(const QModelIndex &) const;

    bool findMatch(unsigned int, const QRegExp &, const QString &) const;
    bool findDateMatch(unsigned int, const date &, const date &, const QString &) const;
    bool findFloatMatch(unsigned int, float, float, const QString &) const;
    bool findIntegerMatch(unsigned int, unsigned int, unsigned int, const QString &) const;
    bool findBoolMatch(unsigned int, bool, const QString &) const;

    bool restore(const QModelIndex &);
    bool lend(const QModelIndex &);

    float calculateValue(const QModelIndex &) const;
    float calculateProfit(const QModelIndex &) const;
    float calculateIncome(const QModelIndex &) const;
    float calculateExpense(const QModelIndex &) const;

    float calculateTotalValue() const;
    float calculateTotalProfit() const;
    float calculateTotalIncome() const;
    float calculateTotalExpense() const;

    void loadFile(const std::string &);
    void saveFile(const std::string &) const;
};

#endif // LISTMODELADAPTER_H
