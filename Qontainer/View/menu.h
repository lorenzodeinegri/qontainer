#ifndef MENU_H
#define MENU_H


#include <QMenuBar>

class Menu : public QMenuBar {
    Q_OBJECT

public:
    explicit Menu(QWidget * = nullptr);

signals:
    void load();
    void save();
    void saveName();
    void exit();

    void insert();
    void interact();

    void about();
};

#endif // MENU_H
