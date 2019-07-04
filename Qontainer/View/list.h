#ifndef LIST_H
#define LIST_H

#include <QListView>
#include <QMouseEvent>

class List : public QListView {
    Q_OBJECT

public:
    List(QWidget * = nullptr);

    QSize sizeHint() const override;
    void mousePressEvent(QMouseEvent *) override;
};

#endif // LIST_H
