#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "container.h"
#include "deeppointer.h"
#include "date.h"
#include "material.h"
#include "artwork.h"
#include "literarywork.h"
#include "sculpture.h"
#include "picture.h"
#include "act.h"
#include "letter.h"

#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMessageBox>

class fileHandler {
private:
    std::string filePath;

public:
    fileHandler(const std::string & = ":/Data/data.xml");
    Container<DeepPointer<Material>> read() const;
    void write(const Container<DeepPointer<Material>> &) const;
};

#endif // FILEHANDLER_H
