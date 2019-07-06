#include "insert.h"

void Insert::clearCommonValues() {
    imagePath = ":/Photos/photoNotAvailable.jpeg";
    imageLabel->setPixmap(QPixmap(QString::fromStdString(imagePath)));

    sectorEdit->setText("");
    valueEdit->setText("");
    proprietaryFalse->setChecked(true);
    stateFalse->setChecked(true);
    availabilityTrue->setChecked(true);
    authorEdit->setText("");
    titleEdit->setText("");
    placeEdit->setText("");
    dateEdit->setDate(QDate(0, 0, 0));
}

void Insert::clearArtValues() const {
    materialEdit->setText("");
    techniqueEdit->setText("");
    movementEdit->setText("");
    subjectEdit->setText("");
}

void Insert::setArtValuesVisibility(bool visibility) const {
    artTypeEdit->setVisible(visibility);
    materialEdit->setVisible(visibility);
    techniqueEdit->setVisible(visibility);
    movementEdit->setVisible(visibility);
    subjectEdit->setVisible(visibility);
    materialLabel->setVisible(visibility);
    techniqueLabel->setVisible(visibility);
    movementLabel->setVisible(visibility);
    subjectLabel->setVisible(visibility);
}

void Insert::clearLiteraryValues() const {
    textTrue->setChecked(true);
    writingTrue->setChecked(true);
    languageEdit->setText("");
    styleEdit->setText("");
}

void Insert::setLiteraryValuesVisibility(bool visibility) const {
    literaryTypeEdit->setVisible(visibility);
    textTrue->setVisible(visibility);
    writingTrue->setVisible(visibility);
    textFalse->setVisible(visibility);
    writingFalse->setVisible(visibility);
    languageEdit->setVisible(visibility);
    styleEdit->setVisible(visibility);
    languageLabel->setVisible(visibility);
    styleLabel->setVisible(visibility);
}

void Insert::clearSculptureValues() const {
    shapeEdit->setText("");
}

void Insert::setSculptureValuesVisibility(bool visibility) const {
    shapeEdit->setVisible(visibility);
    shapeLabel->setVisible(visibility);
}

void Insert::clearPictureValues() const {
    formatFalse->setChecked(true);
}

void Insert::setPictureValuesVisibility(bool visibility) const {
    formatTrue->setVisible(visibility);
    formatFalse->setVisible(visibility);
}

void Insert::clearActValues() const {
    objectEdit->setText("");
}

void Insert::setActValuesVisibility(bool visibility) const {
    objectEdit->setVisible(visibility);
    objectLabel->setVisible(visibility);
}

void Insert::clearLetterValues() const {
    addresseeEdit->setText("");
}

void Insert::setLetterValuesVisibility(bool visibility) const {
    addresseeEdit->setVisible(visibility);
    addresseeLabel->setVisible(visibility);
}

void Insert::changeCategory(const QString & category) const {
    clearArtValues();
    clearLiteraryValues();

    setArtValuesVisibility(false);
    setLiteraryValuesVisibility(false);

    if (category == "Opera d'arte") {
        setArtValuesVisibility(true);
        artTypeEdit->setCurrentIndex(0);
    }
    else if (category == "Opera letteraria") {
        setLiteraryValuesVisibility(true);
        literaryTypeEdit->setCurrentIndex(0);
    }
}

void Insert::changeArtType(const QString & artType) const {
    clearSculptureValues();
    clearPictureValues();

    setSculptureValuesVisibility(false);
    setPictureValuesVisibility(false);

    if (artType == "Scultura")
        setSculptureValuesVisibility(true);
    else if (artType == "Dipinto")
        setPictureValuesVisibility(true);
}

void Insert::changeLiteraryType(const QString & literaryType) const {
    clearActValues();
    clearLetterValues();

    setActValuesVisibility(false);
    setLetterValuesVisibility(false);

    if (literaryType == "Atto")
        setActValuesVisibility(true);
    else if (literaryType == "Lettera")
        setLetterValuesVisibility(true);
}

void Insert::changeImage() {
    QString photoPath(QFileDialog::getOpenFileName(this, "Selezionare la nuova foto", ":/Photos", "Images (*.png *.jpg *.jpeg)"));
    if (!photoPath.isNull()) {
        QString newPath(":/Photos/" + photoPath.section("/", -1, -1));

        QFile photo(photoPath);
        if (photo.copy(newPath)) {
            imageLabel->setPixmap(QPixmap(newPath));
            imagePath = newPath.toStdString();
        }
        else
            throw ImageException("Errore durante la modifica dell'immagine!\nVerificare che il file sia chiuso o provare a cambiare nome!");
    }
}

void Insert::insert() const {
    Material * material = nullptr;

    if (categoryEdit->currentText() == "Opera d'arte") {
        if (artTypeEdit->currentText() == "Scultura") {
            material = new Sculpture(sectorEdit->text().toUInt(),
                                     valueEdit->text().toFloat(),
                                     proprietaryTrue->isChecked(),
                                     stateTrue->isChecked(),
                                     availabilityTrue->isChecked(),
                                     shapeEdit->text().isEmpty() ? "Sconosciuta" : shapeEdit->text().toStdString(),
                                     materialEdit->text().isEmpty() ? "Sconosciuto" : materialEdit->text().toStdString(),
                                     techniqueEdit->text().isEmpty() ? "Sconosciuta" : techniqueEdit->text().toStdString(),
                                     movementEdit->text().isEmpty() ? "Sconosciuto" : movementEdit->text().toStdString(),
                                     subjectEdit->text().isEmpty() ? "Sconosciuto" : subjectEdit->text().toStdString(),
                                     authorEdit->text().isEmpty() ? "Sconosciuto" : authorEdit->text().toStdString(),
                                     titleEdit->text().isEmpty() ? "Sconosciuto" : titleEdit->text().toStdString(),
                                     placeEdit->text().isEmpty() ? "Sconosciuto" : placeEdit->text().toStdString(),
                                     dateEdit->date().toString().toStdString(),
                                     imagePath,
                                     0,
                                     0,
                                     0.0f,
                                     0.0f);
        }
        else if (artTypeEdit->currentText() == "Dipinto") {
            material = new Picture(sectorEdit->text().toUInt(),
                                   valueEdit->text().toFloat(),
                                   proprietaryTrue->isChecked(),
                                   stateTrue->isChecked(),
                                   availabilityTrue->isChecked(),
                                   formatTrue->isChecked(),
                                   materialEdit->text().isEmpty() ? "Sconosciuto" : materialEdit->text().toStdString(),
                                   techniqueEdit->text().isEmpty() ? "Sconosciuta" : techniqueEdit->text().toStdString(),
                                   movementEdit->text().isEmpty() ? "Sconosciuto" : movementEdit->text().toStdString(),
                                   subjectEdit->text().isEmpty() ? "Sconosciuto" : subjectEdit->text().toStdString(),
                                   authorEdit->text().isEmpty() ? "Sconosciuto" : authorEdit->text().toStdString(),
                                   titleEdit->text().isEmpty() ? "Sconosciuto" : titleEdit->text().toStdString(),
                                   placeEdit->text().isEmpty() ? "Sconosciuto" : placeEdit->text().toStdString(),
                                   dateEdit->date().toString().toStdString(),
                                   imagePath,
                                   0,
                                   0,
                                   0.0f,
                                   0.0f);
        }
    }
    else if (categoryEdit->currentText() == "Opera letteraria") {
        if (literaryTypeEdit->currentText() == "Atto") {
            material = new Act(sectorEdit->text().toUInt(),
                               valueEdit->text().toFloat(),
                               proprietaryTrue->isChecked(),
                               stateTrue->isChecked(),
                               availabilityTrue->isChecked(),
                               objectEdit->text().isEmpty() ? "Sconosciuto" : objectEdit->text().toStdString(),
                               textTrue->isChecked(),
                               writingTrue->isChecked(),
                               languageEdit->text().isEmpty() ? "Sconosciuta" : languageEdit->text().toStdString(),
                               styleEdit->text().isEmpty() ? "Sconosciuto" : styleEdit->text().toStdString(),
                               authorEdit->text().isEmpty() ? "Sconosciuto" : authorEdit->text().toStdString(),
                               titleEdit->text().isEmpty() ? "Sconosciuto" : titleEdit->text().toStdString(),
                               placeEdit->text().isEmpty() ? "Sconosciuto" : placeEdit->text().toStdString(),
                               dateEdit->date().toString().toStdString(),
                               imagePath,
                               0,
                               0,
                               0.0f,
                               0.0f);
        }
        else if (literaryTypeEdit->currentText() == "Lettera") {
            material = new Letter(sectorEdit->text().toUInt(),
                                  valueEdit->text().toFloat(),
                                  proprietaryTrue->isChecked(),
                                  stateTrue->isChecked(),
                                  availabilityTrue->isChecked(),
                                  addresseeEdit->text().isEmpty() ? "Sconosciuto" : addresseeEdit->text().toStdString(),
                                  textTrue->isChecked(),
                                  writingTrue->isChecked(),
                                  languageEdit->text().isEmpty() ? "Sconosciuta" : languageEdit->text().toStdString(),
                                  styleEdit->text().isEmpty() ? "Sconosciuto" : styleEdit->text().toStdString(),
                                  authorEdit->text().isEmpty() ? "Sconosciuto" : authorEdit->text().toStdString(),
                                  titleEdit->text().isEmpty() ? "Sconosciuto" : titleEdit->text().toStdString(),
                                  placeEdit->text().isEmpty() ? "Sconosciuto" : placeEdit->text().toStdString(),
                                  dateEdit->date().toString().toStdString(),
                                  imagePath,
                                  0,
                                  0,
                                  0.0f,
                                  0.0f);
        }
    }

    if (material)
        emit insertMaterial(material);
}

void Insert::cancel() {
    clearCommonValues();
    clearArtValues();
    clearLiteraryValues();
    clearSculptureValues();
    clearPictureValues();
    clearActValues();
    clearLetterValues();
}

Insert::Insert(QWidget * parent) :
    QWidget(parent),
    categoryEdit(new CategoryComboBox(this)),
    artTypeEdit(new ArtTypeComboBox(this)),
    literaryTypeEdit(new LiteraryTypeComboBox(this)),
    imagePath(":/Photos/photoNotAvailable.jpeg"),
    imageLabel(new QLabel(this)),
    sectorLabel(new QLabel("Settore:", this)),
    sectorEdit(new QLineEdit("", this)),
    valueLabel(new QLabel("Valore base:", this)),
    valueEdit(new QLineEdit("", this)),
    authorLabel(new QLabel("Autore:", this)),
    authorEdit(new QLineEdit("", this)),
    titleLabel(new QLabel("Titolo:", this)),
    titleEdit(new QLineEdit("", this)),
    placeLabel(new QLabel("Luogo:", this)),
    placeEdit(new QLineEdit("", this)),
    materialLabel(new QLabel("Materiale:", this)),
    materialEdit(new QLineEdit("", this)),
    techniqueLabel(new QLabel("Tecnica:", this)),
    techniqueEdit(new QLineEdit("", this)),
    movementLabel(new QLabel("Movimento:", this)),
    movementEdit(new QLineEdit("", this)),
    subjectLabel(new QLabel("Soggetto:", this)),
    subjectEdit(new QLineEdit("", this)),
    languageLabel(new QLabel("Lingua:", this)),
    languageEdit(new QLineEdit("", this)),
    styleLabel(new QLabel("Stile:", this)),
    styleEdit(new QLineEdit("", this)),
    shapeLabel(new QLabel("Forma:", this)),
    shapeEdit(new QLineEdit("", this)),
    objectLabel(new QLabel("Oggetto:", this)),
    objectEdit(new QLineEdit("", this)),
    addresseeLabel(new QLabel("Destinatario:", this)),
    addresseeEdit(new QLineEdit("", this)),
    dateLabel(new QLabel("Data:", this)),
    dateEdit(new QDateEdit(QDate::fromString("00/00/0000", "dd.MM.yyyy"), this)),
    proprietaryTrue(new QRadioButton("Privato/a", this)),
    stateTrue(new QRadioButton("Danneggiato/a", this)),
    availabilityTrue(new QRadioButton("Disponibile", this)),
    textTrue(new QRadioButton("Completo/a", this)),
    writingTrue(new QRadioButton("Manoscritto", this)),
    formatTrue(new QRadioButton("Fotografia", this)),
    proprietaryFalse(new QRadioButton("Pubblico/a", this)),
    stateFalse(new QRadioButton("Integro/a", this)),
    availabilityFalse(new QRadioButton("Inservibile", this)),
    textFalse(new QRadioButton("Incompleto/a", this)),
    writingFalse(new QRadioButton("Dattiloscritto", this)),
    formatFalse(new QRadioButton("Rappresentazione", this))
{
    QButtonGroup * proprietaryEdit = new QButtonGroup(this);
    QButtonGroup * stateEdit = new QButtonGroup(this);
    QButtonGroup * availabilityEdit = new QButtonGroup(this);
    QButtonGroup * textEdit = new QButtonGroup(this);
    QButtonGroup * writingEdit = new QButtonGroup(this);
    QButtonGroup * formatEdit = new QButtonGroup(this);

    QVBoxLayout * mainForm = new QVBoxLayout(this);

    QHBoxLayout * topForm = new QHBoxLayout(this);
    QHBoxLayout * middleForm = new QHBoxLayout(this);
    QHBoxLayout * bottomForm = new QHBoxLayout(this);

    QLabel * category = new QLabel("Categoria:", this);
    QLabel * typology = new QLabel("Tipologia:", this);

    topForm->addWidget(category);
    topForm->addWidget(categoryEdit);
    topForm->addWidget(typology);
    topForm->addWidget(artTypeEdit);
    topForm->addWidget(literaryTypeEdit);

    QVBoxLayout * imageForm = new QVBoxLayout(this);
    imageLabel->setPixmap(QPixmap(QString::fromStdString(imagePath)));
    QPushButton * imageButton = new QPushButton("Modifica", this);
    imageForm->addWidget(imageLabel);
    imageForm->addWidget(imageButton);

    QVBoxLayout * dataForm = new QVBoxLayout(this);

    QHBoxLayout * sectorForm = new QHBoxLayout(this);
    sectorForm->addWidget(sectorLabel);
    sectorEdit->setValidator(new QIntValidator(1, 100));
    sectorForm->addWidget(sectorEdit);

    QHBoxLayout * valueForm = new QHBoxLayout(this);
    valueForm->addWidget(valueLabel);
    valueEdit->setValidator(new QDoubleValidator(0.0, 1000000.0, 2));
    valueForm->addWidget(valueEdit);

    QHBoxLayout * proprietaryForm = new QHBoxLayout(this);
    proprietaryEdit->addButton(proprietaryTrue, 1);
    proprietaryEdit->addButton(proprietaryFalse, 2);
    proprietaryFalse->setChecked(true);
    proprietaryForm->addWidget(proprietaryTrue);
    proprietaryForm->addWidget(proprietaryFalse);

    QHBoxLayout * damagedForm = new QHBoxLayout(this);
    stateEdit->addButton(stateTrue, 1);
    stateEdit->addButton(stateFalse, 2);
    stateFalse->setChecked(true);
    damagedForm->addWidget(stateTrue);
    damagedForm->addWidget(stateFalse);

    QHBoxLayout * availableForm = new QHBoxLayout(this);
    availabilityEdit->addButton(availabilityTrue, 1);
    availabilityEdit->addButton(availabilityFalse, 2);
    availabilityTrue->setChecked(true);
    availableForm->addWidget(availabilityTrue);
    availableForm->addWidget(availabilityFalse);

    QHBoxLayout * authorForm = new QHBoxLayout(this);
    authorForm->addWidget(authorLabel);
    authorForm->addWidget(authorEdit);

    QHBoxLayout * titleForm = new QHBoxLayout(this);
    titleForm->addWidget(titleLabel);
    titleForm->addWidget(titleEdit);

    QHBoxLayout * placeForm = new QHBoxLayout(this);
    placeForm->addWidget(placeLabel);
    placeForm->addWidget(placeEdit);

    QHBoxLayout * dateForm = new QHBoxLayout(this);
    dateForm->addWidget(dateLabel);
    dateForm->addWidget(dateEdit);

    dataForm->addLayout(sectorForm);
    dataForm->addLayout(valueForm);
    dataForm->addLayout(proprietaryForm);
    dataForm->addLayout(damagedForm);
    dataForm->addLayout(availableForm);
    dataForm->addLayout(authorForm);
    dataForm->addLayout(titleForm);
    dataForm->addLayout(placeForm);
    dataForm->addLayout(dateForm);

    QHBoxLayout * materialForm = new QHBoxLayout(this);
    materialForm->addWidget(materialLabel);
    materialForm->addWidget(materialEdit);

    QHBoxLayout * techniqueForm = new QHBoxLayout(this);
    techniqueForm->addWidget(techniqueLabel);
    techniqueForm->addWidget(techniqueEdit);

    QHBoxLayout * movementForm = new QHBoxLayout(this);
    movementForm->addWidget(movementLabel);
    movementForm->addWidget(movementEdit);

    QHBoxLayout * subjectForm = new QHBoxLayout(this);
    subjectForm->addWidget(subjectLabel);
    subjectForm->addWidget(subjectEdit);

    dataForm->addLayout(materialForm);
    dataForm->addLayout(techniqueForm);
    dataForm->addLayout(movementForm);
    dataForm->addLayout(subjectForm);

    QHBoxLayout * completeForm = new QHBoxLayout(this);
    textEdit->addButton(textTrue, 1);
    textEdit->addButton(textFalse, 2);
    textTrue->setChecked(true);
    completeForm->addWidget(textTrue);
    completeForm->addWidget(textFalse);

    QHBoxLayout * handwrittenForm = new QHBoxLayout(this);
    writingEdit->addButton(writingTrue, 1);
    writingEdit->addButton(writingFalse, 2);
    writingTrue->setChecked(true);
    handwrittenForm->addWidget(writingTrue);
    handwrittenForm->addWidget(writingFalse);

    QHBoxLayout * languageForm = new QHBoxLayout(this);
    languageForm->addWidget(languageLabel);
    languageForm->addWidget(languageEdit);

    QHBoxLayout * styleForm = new QHBoxLayout(this);
    styleForm->addWidget(styleLabel);
    styleForm->addWidget(styleEdit);

    dataForm->addLayout(completeForm);
    dataForm->addLayout(handwrittenForm);
    dataForm->addLayout(languageForm);
    dataForm->addLayout(styleForm);

    QHBoxLayout * shapeForm = new QHBoxLayout(this);
    shapeForm->addWidget(shapeLabel);
    shapeForm->addWidget(shapeEdit);

    dataForm->addLayout(shapeForm);

    QHBoxLayout * photographyForm = new QHBoxLayout(this);
    formatEdit->addButton(formatTrue, 1);
    formatEdit->addButton(formatFalse, 2);
    formatFalse->setChecked(true);
    photographyForm->addWidget(formatTrue);
    photographyForm->addWidget(formatFalse);

    dataForm->addLayout(photographyForm);

    QHBoxLayout * objectForm = new QHBoxLayout(this);
    objectForm->addWidget(objectLabel);
    objectForm->addWidget(objectEdit);

    dataForm->addLayout(objectForm);

    QHBoxLayout * addresseeForm = new QHBoxLayout(this);
    addresseeForm->addWidget(addresseeLabel);
    addresseeForm->addWidget(addresseeEdit);

    dataForm->addLayout(addresseeForm);

    middleForm->addLayout(dataForm);
    middleForm->addLayout(imageForm);

    QPushButton * insertButton = new QPushButton("Inserisci", this);
    QPushButton * cancelButton = new QPushButton("Cancella", this);

    insertButton->setToolTip("Inserisci un nuovo materiale");
    cancelButton->setToolTip("Cancella tutti i dati inseriti nel form");

    insertButton->setToolTipDuration(-1);
    cancelButton->setToolTipDuration(-1);

    bottomForm->addWidget(insertButton);
    bottomForm->addWidget(cancelButton);

    mainForm->addLayout(topForm);
    mainForm->addLayout(middleForm);
    mainForm->addLayout(bottomForm);

    setLayout(mainForm);

    connect(categoryEdit, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeCategory(const QString &)));
    connect(artTypeEdit, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeArtType(const QString &)));
    connect(literaryTypeEdit, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeLiteraryType(const QString &)));

    connect(imageButton, SIGNAL(clicked()), this, SLOT(changeImage()));
    connect(insertButton, SIGNAL(clicked()), this, SLOT(insert()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    emit(categoryEdit->currentTextChanged((categoryEdit->currentText())));
}
