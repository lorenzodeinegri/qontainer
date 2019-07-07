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
#include "fileexception.h"

#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>


class FileHandler {
private:
    std::string filePath;

public:
    FileHandler(const std::string & = ":/Data/data.xml");

    Container<DeepPointer<Material>> read() const;
    void write(const Container<DeepPointer<Material>> &) const;

    std::string getFilePath() const;
    void setFilePath(const std::string &);
};

#endif // FILEHANDLER_H
