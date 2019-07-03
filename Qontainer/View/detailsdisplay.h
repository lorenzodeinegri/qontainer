#ifndef DETAILSDISPLAY_H
#define DETAILSDISPLAY_H

#include "material.h"
#include "artwork.h"
#include "literarywork.h"
#include "sculpture.h"
#include "picture.h"
#include "act.h"
#include "letter.h"

#include <QWidget>
#include <QIcon>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

class DetailsDisplay : public QWidget {
    Q_OBJECT

public:
    explicit DetailsDisplay(Material *, QWidget *parent = nullptr);
};

#endif // DETAILSDISPLAY_H
