#ifndef LISTMODELADAPTER_H
#define LISTMODELADAPTER_H

#include "model.h"
#include "date.h"

#include <QAbstractListModel>

class ListModelAdapter : public QAbstractListModel {
private:
    Model * model;

public:
    ListModelAdapter(QObject * = nullptr);
    ~ListModelAdapter() override;

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &, int = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &, const QVariant &, int) override;

    Qt::ItemFlags flags(const QModelIndex &) const override;

    bool insertRows(int, int = 1, const QModelIndex & = QModelIndex()) override;
    bool removeRows(int, int = 1, const QModelIndex & = QModelIndex()) override;

    void showDisplay(const QModelIndex &) const;
    void showModify(const QModelIndex &);

    bool findMatch(unsigned int, const QRegExp &, const QString &) const;
    bool findDateMatch(unsigned int, const date &, const date &, const QString &) const;

    void restore(const QModelIndex &);
    void lend(const QModelIndex &);

    float calculateValue(const QModelIndex &) const;
    float calculateProfit(const QModelIndex &) const;

    float calculateTotalValue() const;
    float calculateTotalProfit() const;
    float calculateTotalIncome() const;
    float calculateTotalExpense() const;

    void loadFile(const std::string &);
    void saveFile(const std::string &) const;
};

#endif // LISTMODELADAPTER_H
