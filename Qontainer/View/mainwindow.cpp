#include "mainwindow.h"

#include <QIcon>

MainWindow::MainWindow(QWidget * parent) : QWidget(parent) {
    setWindowIcon(QIcon(":/Icons/icon.png"));
}

MainWindow::~MainWindow() {}
