#include "mainwindow.h"

#include <QApplication>

int main(int argc, char * argv[]) {
    QApplication application(argc, argv);
    MainWindow mainWindow;
    mainWindow.setAttribute(Qt::WA_DeleteOnClose);
    mainWindow.show();

    return application.exec();
}
