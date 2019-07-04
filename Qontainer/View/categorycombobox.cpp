#include "categorycombobox.h"

CategoryComboBox::CategoryComboBox(QWidget * parent) : QComboBox(parent) {
    addItem("");
    addItem("Opera d'arte");
    addItem("Opera letteraria");
}
