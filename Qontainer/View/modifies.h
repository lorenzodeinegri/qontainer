#ifndef MODIFIES_H
#define MODIFIES_H

#include "material.h"
#include "artwork.h"
#include "literarywork.h"
#include "sculpture.h"
#include "picture.h"
#include "act.h"
#include "letter.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QButtonGroup>
#include <QPushButton>
#include <QRadioButton>
#include <QDateEdit>
#include <QIcon>
#include <QPixmap>
#include <QFileDialog>
#include <QModelIndex>
#include <QMessageBox>
#include <QFormLayout>
#include <QCoreApplication>

class Modifies : public QWidget {
    Q_OBJECT

private:
    Material * material;

    const QModelIndex begin;
    const QModelIndex end;

    std::string imagePath;

    QLabel * imageLabel;

    QLineEdit * sectorEdit;
    QLineEdit * valueEdit;
    QLineEdit * authorEdit;
    QLineEdit * titleEdit;
    QLineEdit * placeEdit;
    QDateEdit * dateEdit;
    QLineEdit * materialEdit;
    QLineEdit * techniqueEdit;
    QLineEdit * movementEdit;
    QLineEdit * subjectEdit;
    QLineEdit * languageEdit;
    QLineEdit * styleEdit;
    QLineEdit * shapeEdit;
    QLineEdit * objectEdit;
    QLineEdit * addresseeEdit;

    QButtonGroup * proprietaryEdit;
    QButtonGroup * stateEdit;
    QButtonGroup * availabilityEdit;
    QButtonGroup * textEdit;
    QButtonGroup * writingEdit;
    QButtonGroup * formatEdit;

private slots:
    void changeImage();
    void save() const;
    void cancel();

public:
    explicit Modifies(Material *, const QModelIndex &, const QModelIndex &, QWidget * = nullptr);

signals:
    void dataChanged(const QModelIndex &, const QModelIndex &) const;
};

#endif // MODIFIES_H
