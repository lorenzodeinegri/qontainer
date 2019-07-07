#include "arttypecombobox.h"

ArtTypeComboBox::ArtTypeComboBox(QWidget * parent) : QComboBox(parent) {
    addItem("Scultura");
    addItem("Dipinto");
}
