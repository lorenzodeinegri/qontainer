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

}

void MainWindow::interactShow() const {

}

void MainWindow::about() const {

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
    QWidget(parent)
{
    setWindowIcon(QIcon(":/Icons/icon.png"));
    setWindowTitle("Museo");
}
