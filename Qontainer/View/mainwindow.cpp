#include "mainwindow.h"

void MainWindow::load() const {

}

void MainWindow::loadFile() const {

}

void MainWindow::saveFile() const {

}

void MainWindow::saveFileName() const {

}

void MainWindow::exit() const {

}

void MainWindow::insertShow() const {
    insert->setVisible(true);
    interact->setVisible(false);
}

void MainWindow::interactShow() const {
    insert->setVisible(false);
    interact->setVisible(true);
}

void MainWindow::about() {
    QMessageBox::about(this,
                       "Informazioni sull'applicazione",
                       "Progetto per il corso di programmazione ad oggetti\nLorenzo Dei Negri - 1161729");
}

void MainWindow::insertMaterial(Material * material) const {

}

void MainWindow::searchRegularExpressions(const QString & regularExpression, const QString & filter) const {

}

void MainWindow::searchDates(const QDate & first, const QDate & last, const QString & filter) const {

}

void MainWindow::searchFloats(float first, float last, const QString & filter) const {

}

void MainWindow::searchIntegers(unsigned int first, unsigned int last, const QString & filter) const {

}

void MainWindow::searchBools(bool value, const QString & filter) const {

}

void MainWindow::details(const QModelIndex & modelIndex) const {

}

void MainWindow::modifies(const QModelIndex & modelIndex) const {

}

void MainWindow::restore(const QModelIndex & modelIndex) const {

}

void MainWindow::lend(const QModelIndex & modelIndex) const {

}

void MainWindow::calculateValue(const QModelIndex & modelIndex) const {

}

void MainWindow::calculateProfit(const QModelIndex & modelIndex) const {

}

void MainWindow::calculateIncome(const QModelIndex & modelIndex) const {

}

void MainWindow::calculateExpense(const QModelIndex & modelIndex) const {

}

void MainWindow::calculateTotalValue(const QModelIndexList & modelIndexList) const {

}

void MainWindow::calculateTotalProfit(const QModelIndexList & modelIndexList) const {

}

void MainWindow::calculateTotalIncome(const QModelIndexList & modelIndexList) const {

}

void MainWindow::calculateTotalExpense(const QModelIndexList & modelIndexList) const {

}

void MainWindow::deletes(const QModelIndex & modelIndex) const {

}

void MainWindow::closeEvent(QCloseEvent * event) {

}

MainWindow::MainWindow(QWidget * parent) :
    QWidget(parent),
    filePath(":/Data/data.xml"),
    searchComboBox(new SearchComboBox(this)),
    list(new List(this)),
    listModelAdapter(new ListModelAdapter(this)),
    filterProxyModel(new SortFilterProxyModel(searchComboBox, this)),
    menu(new Menu(this)),
    insert(new Insert(this)),
    interact(new Interact(list, searchComboBox, this))
{
    setWindowIcon(QIcon(":/Icons/icon.png"));
    setWindowTitle("Museo");

    filterProxyModel->setSourceModel(listModelAdapter);
    list->setModel(filterProxyModel);

    QHBoxLayout * mainLayout = new QHBoxLayout(this);
    mainLayout->setMenuBar(menu);
    mainLayout->addWidget(insert);
    mainLayout->addWidget(interact);

    insertShow();

    setLayout(mainLayout);


    connect(menu, SIGNAL(insert()), this, SLOT(insertShow()));
    connect(menu, SIGNAL(interact()), this, SLOT(interactShow()));
    connect(menu, SIGNAL(about()), this, SLOT(about()));
}
