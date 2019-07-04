#include "arttypecombobox.h"

ArtTypeComboBox::ArtTypeComboBox(QWidget * parent) : QComboBox(parent) {
    addItem("");
    addItem("Scultura");
    addItem("Dipinto");
}
