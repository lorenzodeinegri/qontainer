#include "modifies.h"

void Modifies::changeImage() {
    QString photoPath(QFileDialog::getOpenFileName(this, "Selezionare la nuova foto", ":/Photos", "Images (*.png *.jpg *.jpeg)"));
    if (!photoPath.isNull()) {
        QString newPath(":/Photos/" + photoPath.section("/", -1, -1));

        QFile photo(photoPath);
        if (photo.copy(newPath)) {
            imageLabel->setPixmap(QPixmap(newPath));
            imagePath = newPath.toStdString();
        }
        else {
            QMessageBox::critical(this,
                                  "Seleziona nuova immagine",
                                  "Errore durante la modifica dell'immagine!\nVerificare che il file sia chiuso o provare a cambiare nome!",
                                  QMessageBox::Ok,
                                  QMessageBox::NoButton,
                                  QMessageBox::NoButton);
        }
    }
}

void Modifies::save() const {
    material->setSector(sectorEdit->text().toUInt());
    material->setBaseValue(valueEdit->text().toFloat());
    material->setProprietary(proprietaryEdit->checkedId() == 1 ? true : false);
    material->setDamaged(stateEdit->checkedId() == 1 ? true : false);
    material->setAvailable(availabilityEdit->checkedId() == 1 ? true : false);
    material->setAuthor(authorEdit->text().toStdString());
    material->setTitle(titleEdit->text().toStdString());
    material->setPlace(placeEdit->text().toStdString());
    material->setDate(dateEdit->date().toString("dd/MM/yyyy").toStdString());
    material->setPhoto(imagePath);

    if (material->getMaterialType() == "Opera d'arte") {
        static_cast<ArtWork *>(material)->setMaterial(materialEdit->text().toStdString());
        static_cast<ArtWork *>(material)->setTechnique(techniqueEdit->text().toStdString());
        static_cast<ArtWork *>(material)->setArtMovement(movementEdit->text().toStdString());
        static_cast<ArtWork *>(material)->setSubject(subjectEdit->text().toStdString());

        if (material->getType() == "Scultura") {
            static_cast<Sculpture *>(material)->setShape(shapeEdit->text().toStdString());
        }
        else if (material->getType() == "Dipinto") {
            static_cast<Picture *>(material)->setPhotography(formatEdit->checkedId() == 1 ? true : false);
        }
    }
    else if (material->getMaterialType() == "Opera letteraria") {
        static_cast<LiteraryWork *>(material)->setComplete(textEdit->checkedId() == 1 ? true : false);
        static_cast<LiteraryWork *>(material)->setHandwritten(writingEdit->checkedId() == 1 ? true : false);
        static_cast<LiteraryWork *>(material)->setLanguage(languageEdit->text().toStdString());
        static_cast<LiteraryWork *>(material)->setStyle(styleEdit->text().toStdString());

        if (material->getType() == "Atto") {
            static_cast<Act *>(material)->setObject(objectEdit->text().toStdString());
        }
        else if (material->getType() == "Lettera") {
            static_cast<Letter *>(material)->setAddressee(addresseeEdit->text().toStdString());
        }
    }

    emit dataChanged(begin, end);
}

void Modifies::cancel() {
    imagePath = ":/Photos/photoNotAvailable.jpeg";
    imageLabel->setPixmap(QPixmap(QString::fromStdString(imagePath)));

    sectorEdit->setText("0");
    valueEdit->setText("0.0");
    proprietaryEdit->button(2)->setChecked(true);
    stateEdit->button(2)->setChecked(true);
    availabilityEdit->button(1)->setChecked(true);
    authorEdit->setText("Sconosciuto");
    titleEdit->setText("Sconosciuto");
    placeEdit->setText("Sconosciuto");
    dateEdit->setDate(QDate::fromString("00/00/0000", "dd/MM/yyyy"));

    if (material->getMaterialType() == "Opera d'arte") {
        materialEdit->setText("Sconosciuto");
        techniqueEdit->setText("Sconosciuta");
        movementEdit->setText("Sconosciuto");
        subjectEdit->setText("Sconosciuto");

        if (material->getType() == "Scultura") {
            shapeEdit->setText("Sconosciuta");
        }
        else if (material->getType() == "Dipinto") {
            formatEdit->button(2)->setChecked(true);
        }
    }
    else if (material->getMaterialType() == "Opera letteraria") {
        textEdit->button(1)->setChecked(true);
        writingEdit->button(1)->setChecked(true);
        languageEdit->setText("Sconosciuta");
        styleEdit->setText("Sconosciuto");

        if (material->getType() == "Atto") {
            objectEdit->setText("Sconosciuto");
        }
        else if (material->getType() == "Lettera") {
            addresseeEdit->setText("Sconosciuto");
        }
    }
}

Modifies::Modifies(Material * material, const QModelIndex & begin, const QModelIndex & end, QWidget * parent) :
    QWidget(parent),
    material(material),
    begin(begin),
    end(end),
    imagePath(material->getPhoto()),
    imageLabel(new QLabel(this)),
    sectorEdit(new QLineEdit(QString::fromStdString(std::to_string(material->getSector())), this)),
    valueEdit(new QLineEdit(QString::fromStdString(std::to_string(material->getBaseValue())), this)),
    authorEdit(new QLineEdit(QString::fromStdString(material->getAuthor()), this)),
    titleEdit(new QLineEdit(QString::fromStdString(material->getTitle()), this)),
    placeEdit(new QLineEdit(QString::fromStdString(material->getPlace()), this)),
    materialEdit(nullptr),
    techniqueEdit(nullptr),
    movementEdit(nullptr),
    subjectEdit(nullptr),
    languageEdit(nullptr),
    styleEdit(nullptr),
    shapeEdit(nullptr),
    objectEdit(nullptr),
    addresseeEdit(nullptr),
    dateEdit(new QDateEdit(QDate::fromString(QString::fromStdString(material->getDate())), this)),
    proprietaryEdit(new QButtonGroup(this)),
    stateEdit(new QButtonGroup(this)),
    availabilityEdit(new QButtonGroup(this)),
    textEdit(nullptr),
    writingEdit(nullptr),
    formatEdit(nullptr)
{
    setWindowIcon(QIcon(":/Icons/icon.png"));
    setWindowTitle(QString::fromStdString("Modifica " + material->getType() + " selezionato/a"));

    QVBoxLayout * mainForm = new QVBoxLayout(this);

    QHBoxLayout * middleForm = new QHBoxLayout();
    QHBoxLayout * bottomForm = new QHBoxLayout();

    QVBoxLayout * imageForm = new QVBoxLayout();

    imageLabel->setPixmap(QPixmap(QString::fromStdString(material->getPhoto())));
    QPushButton * imageButton = new QPushButton("Modifica", this);

    imageForm->addWidget(imageLabel);
    imageForm->addWidget(imageButton);

    QFormLayout * dataForm = new QFormLayout();

    sectorEdit->setValidator(new QIntValidator(1, 100, this));
    dataForm->addRow(new QLabel("Settore:", this), sectorEdit);

    valueEdit->setValidator(new QDoubleValidator(0.0, 1000000.0, 2, this));
    dataForm->addRow(new QLabel("Valore base:", this), valueEdit);

    QRadioButton * trueProprietary = new QRadioButton("Privato/a", this);
    QRadioButton * falseProprietary = new QRadioButton("Pubblico/a", this);
    material->isProprietary() ? trueProprietary->setChecked(true) : falseProprietary->setChecked(true);
    proprietaryEdit->addButton(trueProprietary, 1);
    proprietaryEdit->addButton(falseProprietary, 2);

    dataForm->addRow(trueProprietary, falseProprietary);

    QRadioButton * trueState = new QRadioButton("Danneggiato/a", this);
    QRadioButton * falseState = new QRadioButton("Integro/a", this);
    material->isDamaged() ? trueState->setChecked(true) : falseState->setChecked(true);
    stateEdit->addButton(trueState, 1);
    stateEdit->addButton(falseState, 2);

    dataForm->addRow(trueState, falseState);

    QRadioButton * trueAvailability = new QRadioButton("Disponibile", this);
    QRadioButton * falseAvailability = new QRadioButton("Inservibile", this);
    material->isAvailable() ? trueAvailability->setChecked(true) : falseAvailability->setChecked(true);
    availabilityEdit->addButton(trueAvailability, 1);
    availabilityEdit->addButton(falseAvailability, 2);

    dataForm->addRow(trueAvailability, falseAvailability);

    dataForm->addRow(new QLabel("Autore:", this), authorEdit);

    dataForm->addRow(new QLabel("Titolo:", this), titleEdit);

    dataForm->addRow(new QLabel("Luogo:", this), placeEdit);

    dataForm->addRow(new QLabel("Data:", this), dateEdit);

    if (material->getMaterialType() == "Opera d'arte") {
        materialEdit = new QLineEdit(QString::fromStdString(static_cast<ArtWork *>(material)->getMaterial()), this);
        dataForm->addRow(new QLabel("Materiale:", this), materialEdit);

        techniqueEdit = new QLineEdit(QString::fromStdString(static_cast<ArtWork *>(material)->getTechnique()), this);
        dataForm->addRow(new QLabel("Tecnica:", this), techniqueEdit);

        movementEdit = new QLineEdit(QString::fromStdString(static_cast<ArtWork *>(material)->getArtMovement()), this);
        dataForm->addRow(new QLabel("Movimento:", this), movementEdit);

        subjectEdit = new QLineEdit(QString::fromStdString(static_cast<ArtWork *>(material)->getSubject()), this);
        dataForm->addRow(new QLabel("Soggetto:", this), subjectEdit);

        if (material->getType() == "Scultura") {
            shapeEdit = new QLineEdit(QString::fromStdString((static_cast<Sculpture *>(material))->getShape()), this);
            dataForm->addRow(new QLabel("Forma:", this), shapeEdit);
        }
        else if (material->getType() == "Dipinto") {
            QRadioButton * truePhotography = new QRadioButton("Fotografia", this);
            QRadioButton * falsePhotography = new QRadioButton("Rappresentazione", this);
            static_cast<Picture *>(material)->isPhotography() ? truePhotography->setChecked(true) : falsePhotography->setChecked(true);
            formatEdit->addButton(truePhotography, 1);
            formatEdit->addButton(falsePhotography, 2);

            dataForm->addRow(truePhotography, falsePhotography);
        }
    }
    else if (material->getMaterialType() == "Opera letteraria") {
        QRadioButton * trueComplete = new QRadioButton("Completo/a", this);
        QRadioButton * falseComplete = new QRadioButton("Incompleto/a", this);
        static_cast<LiteraryWork *>(material)->isComplete() ? trueComplete->setChecked(true) : falseComplete->setChecked(true);
        textEdit->addButton(trueComplete, 1);
        textEdit->addButton(falseComplete, 2);

        dataForm->addRow(trueComplete, falseComplete);

        QRadioButton * trueHandwritten = new QRadioButton("Manoscritto", this);
        QRadioButton * falseHandwritten = new QRadioButton("Dattiloscritto", this);
        static_cast<LiteraryWork *>(material)->isComplete() ? trueHandwritten->setChecked(true) : falseHandwritten->setChecked(true);
        formatEdit->addButton(trueHandwritten, 1);
        formatEdit->addButton(falseHandwritten, 2);

        dataForm->addRow(trueHandwritten, falseHandwritten);

        languageEdit = new QLineEdit(QString::fromStdString((static_cast<LiteraryWork *>(material))->getLanguage()), this);
        dataForm->addRow(new QLabel("Lingua:", this), languageEdit);

        styleEdit = new QLineEdit(QString::fromStdString((static_cast<LiteraryWork *>(material))->getStyle()), this);
        dataForm->addRow(new QLabel("Stile:", this), styleEdit);

        if (material->getType() == "Atto") {
            objectEdit = new QLineEdit(QString::fromStdString((static_cast<Act *>(material))->getObject()), this);
            dataForm->addRow(new QLabel("Oggetto:", this), objectEdit);
        }
        else if (material->getType() == "Lettera") {
            addresseeEdit = new QLineEdit(QString::fromStdString((static_cast<Letter *>(material))->getAddressee()), this);
            dataForm->addRow(new QLabel("Destinatario:", this), addresseeEdit);
        }
    }

    middleForm->addLayout(dataForm);
    middleForm->addLayout(imageForm);

    QPushButton * saveButton = new QPushButton("Salva", this);
    QPushButton * cancelButton = new QPushButton("Cancella", this);
    QPushButton * exitButton = new QPushButton("Chiudi", this);

    saveButton->setToolTip("Salva le modifiche effettuate");
    cancelButton->setToolTip("Cancella tutti i dati inseriti");
    exitButton->setToolTip("Chiudi la finestra e annulla le modifiche");

    saveButton->setToolTipDuration(-1);
    cancelButton->setToolTipDuration(-1);
    exitButton->setToolTipDuration(-1);

    bottomForm->addWidget(saveButton);
    bottomForm->addWidget(cancelButton);
    bottomForm->addWidget(exitButton);

    mainForm->addLayout(middleForm);
    mainForm->addLayout(bottomForm);

    setLayout(mainForm);

    connect(imageButton, SIGNAL(clicked()), this, SLOT(changeImage()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(close()));
}
