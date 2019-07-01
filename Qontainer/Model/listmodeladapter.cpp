#include "listmodeladapter.h"

ListModelAdapter::ListModelAdapter(QObject * parent) :
    QAbstractListModel(parent),
    model(new Model()) {}

ListModelAdapter::~ListModelAdapter() {
    if (model != nullptr)
        delete model;
}

int ListModelAdapter::rowCount(const QModelIndex &) const {
    return static_cast<int>(model->count());
}

QVariant ListModelAdapter::data(const QModelIndex & index, int role) const {

}

bool ListModelAdapter::setData(const QModelIndex &, const QVariant &, int) {

}

Qt::ItemFlags ListModelAdapter::flags(const QModelIndex &) const {

}

bool ListModelAdapter::insertRows(int, int, const QModelIndex &) {

}

bool ListModelAdapter::removeRows(int, int, const QModelIndex &) {

}

void ListModelAdapter::showDisplay(const QModelIndex &) const {

}

void ListModelAdapter::showModify(const QModelIndex &) {

}

bool ListModelAdapter::findMatch(unsigned int, const QRegExp &, const QString &) const {

}

bool ListModelAdapter::findDateMatch(unsigned int, const date &, const date &, const QString &) const {

}

void ListModelAdapter::restore(const QModelIndex &) {

}

void ListModelAdapter::lend(const QModelIndex &) {

}

float ListModelAdapter::calculateValue(const QModelIndex &) const {

}

float ListModelAdapter::calculateProfit(const QModelIndex &) const {

}

float ListModelAdapter::calculateTotalValue() const {

}

float ListModelAdapter::calculateTotalProfit() const {

}

float ListModelAdapter::calculateTotalIncome() const {

}

float ListModelAdapter::calculateTotalExpense() const {

}

void ListModelAdapter::loadFile(const std::string &) {
    // TODO
}

void ListModelAdapter::saveFile(const std::string &) const {
    // TODO
}
