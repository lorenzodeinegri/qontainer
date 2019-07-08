#include "list.h"

List::List(QWidget * parent) : QListView(parent) {
    setSelectionMode(QAbstractItemView::SingleSelection);
}

QSize List::sizeHint() const {
    return QSize(500, 500);
}

void List::mousePressEvent(QMouseEvent * event) {
    if (!indexAt(event->pos()).isValid()) {
        clearSelection();
        selectionModel()->clearCurrentIndex();
    }

    QListView::mousePressEvent(event);
}
