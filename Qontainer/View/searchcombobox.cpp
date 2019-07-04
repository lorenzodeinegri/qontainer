#include "searchcombobox.h"

SearchComboBox::SearchComboBox(QWidget * parent) : QComboBox(parent) {
    addItem("Settore");
    addItem("Valore Base");
    addItem("Proprieta");
    addItem("Stato");
    addItem("Disponibilita");
    addItem("Autore");
    addItem("Titolo");
    addItem("Luogo");
    addItem("Data");
    addItem("Restauri");
    addItem("Prestiti");
    addItem("Entrate");
    addItem("Uscite");
    addItem("Materiale");
    addItem("Tecnica");
    addItem("Movimento Artistico");
    addItem("Soggetto");
    addItem("Testo");
    addItem("Scrittura");
    addItem("Lingua");
    addItem("Stile");
    addItem("Forma");
    addItem("Formato");
    addItem("Oggetto");
    addItem("Destinatario");
}
