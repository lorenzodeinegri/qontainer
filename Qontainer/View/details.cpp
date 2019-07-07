#include "details.h"

Details::Details(Material * material, QWidget * parent) : QWidget(parent) {
    setWindowIcon(QIcon(":/Icons/icon.png"));
    setWindowTitle(QString::fromStdString("Dettagli " + material->getType() + " selezionato/a"));

    QVBoxLayout * mainForm = new QVBoxLayout(this);

    QFormLayout * dataForm = new QFormLayout();

    QLabel * imageLabel = new QLabel(this);
    imageLabel->setPixmap(QPixmap(QString::fromStdString(material->getPhoto())));

    dataForm->addRow(new QLabel("Settore:", this),
                     new QLabel(QString::fromStdString(std::to_string(material->getSector())), this));

    dataForm->addRow(new QLabel("Valore base:", this),
                     new QLabel(QString::fromStdString(std::to_string(material->getBaseValue())), this));

    dataForm->addRow(new QLabel("Privato/a:", this),
                     new QLabel(QString::fromStdString(material->isProprietary() ? "Si" : "No"), this));

    dataForm->addRow(new QLabel("Danneggiato/a:", this),
                     new QLabel(QString::fromStdString(material->isDamaged() ? "Si" : "No"), this));

    dataForm->addRow(new QLabel("Disponibile:", this),
                     new QLabel(QString::fromStdString(material->isAvailable() ? "Si" : "No"), this));

    dataForm->addRow(new QLabel("Autore:", this),
                     new QLabel(QString::fromStdString(material->getAuthor()), this));

    dataForm->addRow(new QLabel("Titolo:", this),
                     new QLabel(QString::fromStdString(material->getTitle()), this));

    dataForm->addRow(new QLabel("Luogo:", this),
                     new QLabel(QString::fromStdString(material->getPlace()), this));

    dataForm->addRow(new QLabel("Data:", this),
                     new QLabel(QString::fromStdString(material->getDate()), this));

    dataForm->addRow(new QLabel("Restauri:", this),
                     new QLabel(QString::fromStdString(std::to_string(material->getRestorations())), this));

    dataForm->addRow(new QLabel("Prestiti:", this),
                     new QLabel(QString::fromStdString(std::to_string(material->getLoans())), this));

    dataForm->addRow(new QLabel("Entrate:", this),
                     new QLabel(QString::fromStdString(std::to_string(material->getIncome())), this));

    dataForm->addRow(new QLabel("Uscite:", this),
                     new QLabel(QString::fromStdString(std::to_string(material->getExpense())), this));

    if (material->getMaterialType() == "Opera d'arte") {
        dataForm->addRow(new QLabel("Materiale:", this),
                         new QLabel(QString::fromStdString((static_cast<ArtWork *>(material))->getMaterial()), this));

        dataForm->addRow(new QLabel("Tecnica:", this),
                         new QLabel(QString::fromStdString((static_cast<ArtWork *>(material))->getTechnique()), this));

        dataForm->addRow(new QLabel("Movimento:", this),
                         new QLabel(QString::fromStdString((static_cast<ArtWork *>(material))->getArtMovement()), this));

        dataForm->addRow(new QLabel("Soggetto:", this),
                         new QLabel(QString::fromStdString((static_cast<ArtWork *>(material))->getSubject()), this));

        if (material->getType() == "Scultura") {
            dataForm->addRow(new QLabel("Forma:", this),
                             new QLabel(QString::fromStdString((static_cast<Sculpture *>(material))->getShape()), this));
        }
        else if (material->getType() == "Dipinto") {
            dataForm->addRow(new QLabel("Fotografia:", this),
                             new QLabel(QString::fromStdString((static_cast<Picture *>(material))->isPhotography() ? "Si" : "No"), this));
        }
    }
    else if (material->getMaterialType() == "Opera letteraria") {
        dataForm->addRow(new QLabel("Completo:", this),
                         new QLabel(QString::fromStdString((static_cast<LiteraryWork *>(material))->isComplete() ? "Si" : "No"), this));

        dataForm->addRow(new QLabel("Scritto a mano:", this),
                         new QLabel(QString::fromStdString((static_cast<LiteraryWork *>(material))->isHandwritten() ? "Si" : "No"), this));

        dataForm->addRow(new QLabel("Lingua:", this),
                         new QLabel(QString::fromStdString((static_cast<LiteraryWork *>(material))->getLanguage()), this));

        dataForm->addRow(new QLabel("Stile:", this),
                         new QLabel(QString::fromStdString((static_cast<LiteraryWork *>(material))->getStyle()), this));

        if (material->getType() == "Atto") {
            dataForm->addRow(new QLabel("Oggetto:", this),
                             new QLabel(QString::fromStdString((static_cast<Act *>(material))->getObject()), this));
        }
        else if (material->getType() == "Lettera") {
            dataForm->addRow(new QLabel("Destinatario:", this),
                             new QLabel(QString::fromStdString((static_cast<Letter *>(material))->getAddressee()), this));
        }
    }

    mainForm->addWidget(imageLabel);
    mainForm->addLayout(dataForm);

    QPushButton * exitButton = new QPushButton("Chiudi", this);

    exitButton->setToolTip("Chiudi la finestra dei dettagli");
    exitButton->setToolTipDuration(-1);

    mainForm->addWidget(exitButton);

    setLayout(mainForm);

    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}
