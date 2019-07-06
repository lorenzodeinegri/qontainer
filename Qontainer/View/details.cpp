#include "details.h"

Details::Details(Material * material, QWidget * parent) : QWidget(parent) {
    setWindowIcon(QIcon(":/Icons/icon.png"));
    setWindowTitle(QString::fromStdString("Dettagli " + material->getType() + " selezionato/a"));

    QVBoxLayout * mainForm = new QVBoxLayout(this);

    QLabel * imageLabel = new QLabel(this);
    imageLabel->setPixmap(QPixmap(QString::fromStdString(material->getPhoto())));

    QHBoxLayout * sectorForm = new QHBoxLayout(this);
    sectorForm->addWidget(new QLabel("Settore:", this));
    sectorForm->addWidget(new QLabel(QString::fromStdString(std::to_string(material->getSector())), this));

    QHBoxLayout * valueForm = new QHBoxLayout(this);
    valueForm->addWidget(new QLabel("Valore base:", this));
    valueForm->addWidget(new QLabel(QString::fromStdString(std::to_string(material->getBaseValue())), this));

    QHBoxLayout * proprietaryForm = new QHBoxLayout(this);
    proprietaryForm->addWidget(new QLabel("Privato/a:", this));
    proprietaryForm->addWidget(new QLabel(QString::fromStdString(material->isProprietary() ? "Si" : "No"), this));

    QHBoxLayout * damagedForm = new QHBoxLayout(this);
    damagedForm->addWidget(new QLabel("Danneggiato/a:", this));
    damagedForm->addWidget(new QLabel(QString::fromStdString(material->isDamaged() ? "Si" : "No"), this));

    QHBoxLayout * availableForm = new QHBoxLayout(this);
    availableForm->addWidget(new QLabel("Disponibile:", this));
    availableForm->addWidget(new QLabel(QString::fromStdString(material->isAvailable() ? "Si" : "No"), this));

    QHBoxLayout * authorForm = new QHBoxLayout(this);
    authorForm->addWidget(new QLabel("Autore:", this));
    authorForm->addWidget(new QLabel(QString::fromStdString(material->getAuthor()), this));

    QHBoxLayout * titleForm = new QHBoxLayout(this);
    titleForm->addWidget(new QLabel("Titolo:", this));
    titleForm->addWidget(new QLabel(QString::fromStdString(material->getTitle()), this));

    QHBoxLayout * placeForm = new QHBoxLayout(this);
    placeForm->addWidget(new QLabel("Luogo:", this));
    placeForm->addWidget(new QLabel(QString::fromStdString(material->getPlace()), this));

    QHBoxLayout * dateForm = new QHBoxLayout(this);
    dateForm->addWidget(new QLabel("Data:", this));
    dateForm->addWidget(new QLabel(QString::fromStdString(material->getDate()), this));

    QHBoxLayout * restorationsForm = new QHBoxLayout(this);
    restorationsForm->addWidget(new QLabel("Restauri:", this));
    restorationsForm->addWidget(new QLabel(QString::fromStdString(std::to_string(material->getRestorations())), this));

    QHBoxLayout * loansForm = new QHBoxLayout(this);
    loansForm->addWidget(new QLabel("Prestiti:", this));
    loansForm->addWidget(new QLabel(QString::fromStdString(std::to_string(material->getLoans())), this));

    QHBoxLayout * incomeForm = new QHBoxLayout(this);
    incomeForm->addWidget(new QLabel("Entrate:", this));
    incomeForm->addWidget(new QLabel(QString::fromStdString(std::to_string(material->getIncome())), this));

    QHBoxLayout * expenseForm = new QHBoxLayout(this);
    expenseForm->addWidget(new QLabel("Uscite:", this));
    expenseForm->addWidget(new QLabel(QString::fromStdString(std::to_string(material->getExpense())), this));

    mainForm->addWidget(imageLabel);
    mainForm->addLayout(sectorForm);
    mainForm->addLayout(valueForm);
    mainForm->addLayout(proprietaryForm);
    mainForm->addLayout(damagedForm);
    mainForm->addLayout(availableForm);
    mainForm->addLayout(authorForm);
    mainForm->addLayout(titleForm);
    mainForm->addLayout(placeForm);
    mainForm->addLayout(dateForm);
    mainForm->addLayout(restorationsForm);
    mainForm->addLayout(loansForm);
    mainForm->addLayout(incomeForm);
    mainForm->addLayout(expenseForm);

    if (material->getMaterialType() == "Opera d'arte") {
        QHBoxLayout * materialForm = new QHBoxLayout(this);
        materialForm->addWidget(new QLabel("Materiale:", this));
        materialForm->addWidget(new QLabel(QString::fromStdString((static_cast<ArtWork *>(material))->getMaterial()), this));

        QHBoxLayout * techniqueForm = new QHBoxLayout(this);
        techniqueForm->addWidget(new QLabel("Tecnica:", this));
        techniqueForm->addWidget(new QLabel(QString::fromStdString((static_cast<ArtWork *>(material))->getTechnique()), this));

        QHBoxLayout * movementForm = new QHBoxLayout(this);
        movementForm->addWidget(new QLabel("Movimento:", this));
        movementForm->addWidget(new QLabel(QString::fromStdString((static_cast<ArtWork *>(material))->getArtMovement()), this));

        QHBoxLayout * subjectForm = new QHBoxLayout(this);
        subjectForm->addWidget(new QLabel("Soggetto:", this));
        subjectForm->addWidget(new QLabel(QString::fromStdString((static_cast<ArtWork *>(material))->getSubject()), this));

        mainForm->addLayout(materialForm);
        mainForm->addLayout(techniqueForm);
        mainForm->addLayout(movementForm);
        mainForm->addLayout(subjectForm);

        if (material->getType() == "Scultura") {
            QHBoxLayout * shapeForm = new QHBoxLayout(this);
            shapeForm->addWidget(new QLabel("Forma:", this));
            shapeForm->addWidget(new QLabel(QString::fromStdString((static_cast<Sculpture *>(material))->getShape()), this));

            mainForm->addLayout(shapeForm);
        }
        else if (material->getType() == "Dipinto") {
            QHBoxLayout * photographyForm = new QHBoxLayout(this);
            photographyForm->addWidget(new QLabel("Fotografia:", this));
            photographyForm->addWidget(new QLabel(QString::fromStdString((static_cast<Picture *>(material))->isPhotography() ? "Si" : "No"), this));

            mainForm->addLayout(photographyForm);
        }
    }
    else if (material->getMaterialType() == "Opera letteraria") {
        QHBoxLayout * completeForm = new QHBoxLayout(this);
        completeForm->addWidget(new QLabel("Completo:", this));
        completeForm->addWidget(new QLabel(QString::fromStdString((static_cast<LiteraryWork *>(material))->isComplete() ? "Si" : "No"), this));

        QHBoxLayout * handwrittenForm = new QHBoxLayout(this);
        handwrittenForm->addWidget(new QLabel("Scritto a mano:", this));
        handwrittenForm->addWidget(new QLabel(QString::fromStdString((static_cast<LiteraryWork *>(material))->isHandwritten() ? "Si" : "No"), this));

        QHBoxLayout * languageForm = new QHBoxLayout(this);
        languageForm->addWidget(new QLabel("Lingua:", this));
        languageForm->addWidget(new QLabel(QString::fromStdString((static_cast<LiteraryWork *>(material))->getLanguage()), this));

        QHBoxLayout * styleForm = new QHBoxLayout(this);
        styleForm->addWidget(new QLabel("Stile:", this));
        styleForm->addWidget(new QLabel(QString::fromStdString((static_cast<LiteraryWork *>(material))->getStyle()), this));

        mainForm->addLayout(completeForm);
        mainForm->addLayout(handwrittenForm);
        mainForm->addLayout(languageForm);
        mainForm->addLayout(styleForm);

        if (material->getType() == "Atto") {
            QHBoxLayout * objectForm = new QHBoxLayout(this);
            objectForm->addWidget(new QLabel("Oggetto:", this));
            objectForm->addWidget(new QLabel(QString::fromStdString((static_cast<Act *>(material))->getObject()), this));

            mainForm->addLayout(objectForm);
        }
        else if (material->getType() == "Lettera") {
            QHBoxLayout * addresseeForm = new QHBoxLayout(this);
            addresseeForm->addWidget(new QLabel("Destinatario:", this));
            addresseeForm->addWidget(new QLabel(QString::fromStdString((static_cast<Letter *>(material))->getAddressee()), this));

            mainForm->addLayout(addresseeForm);
        }
    }

    QPushButton * exitButton = new QPushButton("Chiudi", this);

    exitButton->setToolTip("Chiudi la finestra dei dettagli");
    exitButton->setToolTipDuration(-1);

    mainForm->addWidget(exitButton);

    setLayout(mainForm);

    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}
