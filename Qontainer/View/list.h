#ifndef LIST_H
#define LIST_H

#include <QListView>
#include <QMouseEvent>

class List : public QListView {
    Q_OBJECT

public:
    explicit List(QWidget * = nullptr);

    virtual QSize sizeHint() const override;
    void mousePressEvent(QMouseEvent *) override;
};

#endif // LIST_H
