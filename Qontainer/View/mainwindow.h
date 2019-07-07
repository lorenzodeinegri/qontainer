#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "material.h"
#include "filehandler.h"
#include "listmodeladapter.h"
#include "sortfilterproxymodel.h"

#include "menu.h"
#include "insert.h"
#include "interact.h"
#include "list.h"
#include "searchcombobox.h"

#include <QWidget>
#include <QMessageBox>

class MainWindow : public QWidget {
    Q_OBJECT

private:
    QString filePath;

    SearchComboBox * searchComboBox;
    List * list;

    ListModelAdapter * listModelAdapter;
    SortFilterProxyModel * filterProxyModel;

    Menu * menu;
    Insert * insert;
    Interact * interact;


    void load() const;

private slots:
    void loadFile() const;
    void saveFile() const;
    void saveFileName() const;
    void exit() const;
    void insertShow() const;
    void interactShow() const;
    void about() const;

    void insertMaterial(Material *) const;

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

protected:
    virtual void closeEvent(QCloseEvent *) override;

public:
    explicit MainWindow(QWidget * = nullptr);
};

#endif // MAINWINDOW_H
