#ifdef __linux__
    #include "View/mainwindow.h"
#elif _WIN32
    #include "View\mainwindow.h"
#endif

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
