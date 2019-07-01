#ifndef SORTFILTERPROXYMODEL_H
#define SORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class SortFilterProxyModel : public QSortFilterProxyModel {
private:


protected:
    bool filterAcceptsRow(int, const QModelIndex &) const override;

public:
    SortFilterProxyModel();
};

#endif // SORTFILTERPROXYMODEL_H
