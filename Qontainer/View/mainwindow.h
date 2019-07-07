#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QIcon>
#include <QMessageBox>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget * = nullptr);
};

#endif // MAINWINDOW_H
