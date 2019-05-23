#include "mainwindow.h"

#include <QIcon>

MainWindow::MainWindow(QWidget * parent) : QWidget(parent) {
    setWindowIcon(QIcon(":/Icons/Icons/icon.png"));
}

MainWindow::~MainWindow() {}
