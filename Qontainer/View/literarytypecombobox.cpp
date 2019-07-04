#include "literarytypecombobox.h"

LiteraryTypeComboBox::LiteraryTypeComboBox(QWidget * parent) : QComboBox(parent) {
    addItem("");
    addItem("Atto");
    addItem("Lettera");
}
