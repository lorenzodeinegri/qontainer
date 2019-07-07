#ifndef INSERT_H
#define INSERT_H

#include "categorycombobox.h"
#include "arttypecombobox.h"
#include "literarytypecombobox.h"
#include "material.h"
#include "artwork.h"
#include "literarywork.h"
#include "sculpture.h"
#include "picture.h"
#include "act.h"
#include "letter.h"

#include <QButtonGroup>
#include <QDateEdit>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

class Insert : public QWidget {
    Q_OBJECT

private:
    CategoryComboBox * categoryEdit;
    ArtTypeComboBox * artTypeEdit;
    LiteraryTypeComboBox * literaryTypeEdit;

    std::string imagePath;

    QLabel * imageLabel;

    QLabel * sectorLabel;
    QLineEdit * sectorEdit;
    QLabel * valueLabel;
    QLineEdit * valueEdit;
    QLabel * authorLabel;
    QLineEdit * authorEdit;
    QLabel * titleLabel;
    QLineEdit * titleEdit;
    QLabel * placeLabel;
    QLineEdit * placeEdit;
    QLabel * materialLabel;
    QLineEdit * materialEdit;
    QLabel * techniqueLabel;
    QLineEdit * techniqueEdit;
    QLabel * movementLabel;
    QLineEdit * movementEdit;
    QLabel * subjectLabel;
    QLineEdit * subjectEdit;
    QLabel * languageLabel;
    QLineEdit * languageEdit;
    QLabel * styleLabel;
    QLineEdit * styleEdit;
    QLabel * shapeLabel;
    QLineEdit * shapeEdit;
    QLabel * objectLabel;
    QLineEdit * objectEdit;
    QLabel * addresseeLabel;
    QLineEdit * addresseeEdit;

    QLabel * dateLabel;
    QDateEdit * dateEdit;

    QRadioButton * proprietaryTrue;
    QRadioButton * stateTrue;
    QRadioButton * availabilityTrue;
    QRadioButton * textTrue;
    QRadioButton * writingTrue;
    QRadioButton * formatTrue;
    QRadioButton * proprietaryFalse;
    QRadioButton * stateFalse;
    QRadioButton * availabilityFalse;
    QRadioButton * textFalse;
    QRadioButton * writingFalse;
    QRadioButton * formatFalse;


    void clearCommonValues();

    void clearArtValues() const;
    void setArtValuesVisibility(bool) const ;
    void clearLiteraryValues() const;
    void setLiteraryValuesVisibility(bool) const;

    void clearSculptureValues() const;
    void setSculptureValuesVisibility(bool) const;
    void clearPictureValues() const;
    void setPictureValuesVisibility(bool) const;
    void clearActValues() const;
    void setActValuesVisibility(bool) const;
    void clearLetterValues() const;
    void setLetterValuesVisibility(bool) const;

private slots:
    void changeCategory(const QString &) const;
    void changeArtType(const QString &) const;
    void changeLiteraryType(const QString &) const;

    void changeImage();

    void insert();
    void cancel();

public:
    explicit Insert(QWidget * = nullptr);

signals:
    void insertMaterial(Material *) const;
};

#endif // INSERT_H
