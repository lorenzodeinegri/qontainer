#include "mainwindow.h"

#include <QApplication>

int main(int argc, char * argv[]) {
    QApplication application(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    application.setQuitOnLastWindowClosed(false);

    int status = application.exec();

    application.closeAllWindows();

    return status;
}
