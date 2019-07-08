#include "insert.h"

void Insert::clearCommonValues() {
    imagePath = ":/Photos/photoNotAvailable.jpeg";
    imageLabel->setPixmap(QPixmap(QString::fromStdString(imagePath)).scaled(QSize(500, 500)));

    sectorEdit->setText("");
    valueEdit->setText("");
    proprietaryFalse->setChecked(true);
    stateFalse->setChecked(true);
    availabilityTrue->setChecked(true);
    authorEdit->setText("");
    titleEdit->setText("");
    placeEdit->setText("");
    dateEdit->setDate(QDate::fromString("01/01/0100", "dd/MM/yyyy"));
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
    artTypology->setVisible(visibility);
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
    literaryTypology->setVisible(visibility);
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

        setActValuesVisibility(false);
        setLetterValuesVisibility(false);

        artTypeEdit->setCurrentIndex(1);
        artTypeEdit->setCurrentIndex(0);
    }
    else if (category == "Opera letteraria") {
        setLiteraryValuesVisibility(true);

        setSculptureValuesVisibility(false);
        setPictureValuesVisibility(false);

        literaryTypeEdit->setCurrentIndex(1);
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
    QString applicationDir = QCoreApplication::applicationDirPath();
    QString photoPath(QFileDialog::getOpenFileName(this, "Selezionare la nuova foto", applicationDir + "/Photos", "Immagini (*.png *.jpg *.jpeg)"));
    if (!photoPath.isNull()) {
        QDir photoDirectory(applicationDir+ "/Photos");
        if (!photoDirectory.exists()) {
            photoDirectory.mkdir(applicationDir + "/Photos");
        }

        QString newPath(applicationDir + "/Photos/" + photoPath.section("/", -1, -1));
        unsigned int number = 1;
        if (QFile::exists(newPath)) {
            newPath = applicationDir + "/Photos/" + QString::fromStdString(std::to_string(number)) + photoPath.section("/", -1, -1);
            ++number;
        }

        if (QFile::copy(photoPath, newPath)) {
            imageLabel->setPixmap(QPixmap(newPath).scaled(QSize(500, 500)));
            imagePath = newPath.toStdString();
        }
        else {
            QMessageBox::critical(this,
                                  "Seleziona nuova immagine",
                                  "Errore durante la modifica dell'immagine!\nVerificare che il file sia accessibile dal programma!",
                                  QMessageBox::Ok,
                                  QMessageBox::NoButton,
                                  QMessageBox::NoButton);

        }
    }
}

void Insert::insert() {
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
                                     dateEdit->date().toString("dd/MM/yyyy").toStdString(),
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
                                   dateEdit->date().toString("dd/MM/yyyy").toStdString(),
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
                               dateEdit->date().toString("dd/MM/yyyy").toStdString(),
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
                                  dateEdit->date().toString("dd/MM/yyyy").toStdString(),
                                  imagePath,
                                  0,
                                  0,
                                  0.0f,
                                  0.0f);
        }
    }

    if (material) {
        emit insertMaterial(material);
        cancel();
        categoryEdit->setCurrentIndex(0);
    }
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
    artTypology(new QLabel("Tipologia:", this)),
    literaryTypology(new QLabel("Tipologia:", this)),
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
    dateLabel(new QLabel("Data:", this)),
    dateEdit(new QDateEdit(QDate(), this)),
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

    QHBoxLayout * middleForm = new QHBoxLayout();
    QHBoxLayout * bottomForm = new QHBoxLayout();

    QLabel * category = new QLabel("Categoria:", this);

    QVBoxLayout * imageForm = new QVBoxLayout();
    imageLabel->setPixmap(QPixmap(QString::fromStdString(imagePath)).scaled(QSize(500, 500)));
    QPushButton * imageButton = new QPushButton("Modifica", this);
    imageForm->addWidget(imageLabel);
    imageForm->addWidget(imageButton);

    QFormLayout * dataForm = new QFormLayout();

    dataForm->addRow(category, categoryEdit);
    dataForm->addRow(artTypology, artTypeEdit);
    dataForm->addRow(literaryTypology, literaryTypeEdit);

    sectorEdit->setValidator(new QIntValidator(1, 100, this));
    dataForm->addRow(sectorLabel, sectorEdit);

    valueEdit->setValidator(new QDoubleValidator(0.0, 1000000000.0, 2, this));
    dataForm->addRow(valueLabel, valueEdit);

    proprietaryEdit->addButton(proprietaryTrue, 1);
    proprietaryEdit->addButton(proprietaryFalse, 2);
    proprietaryFalse->setChecked(true);
    dataForm->addRow(proprietaryTrue, proprietaryFalse);

    stateEdit->addButton(stateTrue, 1);
    stateEdit->addButton(stateFalse, 2);
    stateFalse->setChecked(true);
    dataForm->addRow(stateTrue, stateFalse);

    availabilityEdit->addButton(availabilityTrue, 1);
    availabilityEdit->addButton(availabilityFalse, 2);
    availabilityTrue->setChecked(true);
    dataForm->addRow(availabilityTrue, availabilityFalse);

    dataForm->addRow(authorLabel, authorEdit);

    dataForm->addRow(titleLabel, titleEdit);

    dataForm->addRow(placeLabel, placeEdit);

    dateEdit->setMinimumDate(QDate(100, 1, 1));
    dateEdit->setMaximumDate(QDate::currentDate());

    dateEdit->setDisplayFormat("dd/MM/yyyy");
    dateEdit->setDate(QDate(100, 1, 1));

    dataForm->addRow(dateLabel, dateEdit);

    dataForm->addRow(materialLabel, materialEdit);

    dataForm->addRow(techniqueLabel, techniqueEdit);

    dataForm->addRow(movementLabel, movementEdit);

    dataForm->addRow(subjectLabel, subjectEdit);

    textEdit->addButton(textTrue, 1);
    textEdit->addButton(textFalse, 2);
    textTrue->setChecked(true);
    dataForm->addRow(textTrue, textFalse);

    writingEdit->addButton(writingTrue, 1);
    writingEdit->addButton(writingFalse, 2);
    writingTrue->setChecked(true);
    dataForm->addRow(writingTrue, writingFalse);

    dataForm->addRow(languageLabel, languageEdit);

    dataForm->addRow(styleLabel, styleEdit);

    dataForm->addRow(shapeLabel, shapeEdit);

    formatEdit->addButton(formatTrue, 1);
    formatEdit->addButton(formatFalse, 2);
    formatFalse->setChecked(true);
    dataForm->addRow(formatTrue, formatFalse);

    dataForm->addRow(objectLabel, objectEdit);

    dataForm->addRow(addresseeLabel, addresseeEdit);

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

    mainForm->addLayout(middleForm);
    mainForm->addLayout(bottomForm);

    setLayout(mainForm);

    connect(categoryEdit, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeCategory(const QString &)));
    connect(artTypeEdit, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeArtType(const QString &)));
    connect(literaryTypeEdit, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeLiteraryType(const QString &)));

    connect(imageButton, SIGNAL(clicked()), this, SLOT(changeImage()));
    connect(insertButton, SIGNAL(clicked()), this, SLOT(insert()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    categoryEdit->setCurrentIndex(1);
    categoryEdit->setCurrentIndex(0);
}
