#ifndef MENU_H
#define MENU_H


#include <QMenuBar>

class Menu : public QMenuBar {
    Q_OBJECT

public:
    explicit Menu(QWidget * = nullptr);

signals:
    void load() const;
    void save() const;
    void saveName() const;
    void exit() const;

    void insert() const;
    void interact() const;

    void about() const;
};

#endif // MENU_H
