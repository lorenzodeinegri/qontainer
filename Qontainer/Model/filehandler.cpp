#include "filehandler.h"

FileHandler::FileHandler(const std::string & filePath) : filePath(filePath) {}

Container<DeepPointer<Material>> FileHandler::read() const {
    Container<DeepPointer<Material>> container;

    QFile file(QString::fromStdString(filePath));

    if (file.open(QIODevice::ReadOnly)) {
        QXmlStreamReader xmlReader(&file);

        if (xmlReader.readNextStartElement() && xmlReader.name() == "Materiali") {
            while (xmlReader.readNextStartElement()) {
                if (xmlReader.name() == "Materiale") {
                    std::string type = xmlReader.attributes().value("tipo").toString().toStdString();
                    std::string material_type = xmlReader.attributes().value("tipoMateriale").toString().toStdString();

                    bool proprietary = false, damaged = false, available = true;
                    unsigned int sector = 0, restorations = 0, loans = 0;
                    float base_value = 0.0f, income = 0.0f, expense = 0.0f;
                    std::string author = "Sconosciuto", title = "Sconosciuto", realization_place = "Sconosciuto";
                    std::string photo = ":/Photos/photoNotAvailable.jpeg";
                    date realization_date("00/00/0000");

                    if (xmlReader.readNextStartElement() && xmlReader.name() == "settore")
                        sector = xmlReader.readElementText().toUInt();
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "valore")
                        base_value = xmlReader.readElementText().toFloat();
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "privato")
                        proprietary = xmlReader.readElementText().toStdString() == "Si" ? true : false;
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "danneggiato")
                        damaged = xmlReader.readElementText().toStdString() == "Si" ? true : false;
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "disponibile")
                        available = xmlReader.readElementText().toStdString() == "Si" ? true : false;
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "autore")
                        author = xmlReader.readElementText().toStdString();
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "titolo")
                        title = xmlReader.readElementText().toStdString();
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "luogo")
                        realization_place = xmlReader.readElementText().toStdString();
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "data")
                        realization_date = xmlReader.readElementText().toStdString();
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "foto")
                        photo = xmlReader.readElementText().toStdString();
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "restauri")
                        restorations = xmlReader.readElementText().toUInt();
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "prestiti")
                        loans = xmlReader.readElementText().toUInt();
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "entrate")
                        income = xmlReader.readElementText().toFloat();
                    if (xmlReader.readNextStartElement() && xmlReader.name() == "uscite")
                        expense = xmlReader.readElementText().toFloat();

                    if (material_type == "Opera d'arte") {
                        std::string material = "Sconosciuto", technique = "Sconosciuta", art_movement = "Sconosciuto", subject = "Sconosciuto";

                        if (xmlReader.readNextStartElement() && xmlReader.name() == "materiale")
                            material = xmlReader.readElementText().toStdString();
                        if (xmlReader.readNextStartElement() && xmlReader.name() == "tecnica")
                            technique = xmlReader.readElementText().toStdString();
                        if (xmlReader.readNextStartElement() && xmlReader.name() == "movimento")
                            art_movement = xmlReader.readElementText().toStdString();
                        if (xmlReader.readNextStartElement() && xmlReader.name() == "soggetto")
                            subject = xmlReader.readElementText().toStdString();

                        if (type == "Scultura") {
                            std::string shape = "Sconosciuta";

                            if (xmlReader.readNextStartElement() && xmlReader.name() == "forma")
                                shape = xmlReader.readElementText().toStdString();

                            Material * sculpture = new Sculpture(sector,
                                                                 base_value,
                                                                 proprietary,
                                                                 damaged,
                                                                 available,
                                                                 shape,
                                                                 material,
                                                                 technique,
                                                                 art_movement,
                                                                 subject,
                                                                 author,
                                                                 title,
                                                                 realization_place,
                                                                 realization_date,
                                                                 photo,
                                                                 restorations,
                                                                 loans,
                                                                 income,
                                                                 expense);

                            container.push_back(DeepPointer<Material>(sculpture));
                            delete sculpture;
                        }
                        else if (type == "Dipinto") {
                            bool photography = false;

                            if (xmlReader.readNextStartElement() && xmlReader.name() == "fotografia")
                                photography = xmlReader.readElementText().toStdString() == "Si" ? true : false;

                            Material * picture = new Picture(sector,
                                                             base_value,
                                                             proprietary,
                                                             damaged,
                                                             available,
                                                             photography,
                                                             material,
                                                             technique,
                                                             art_movement,
                                                             subject,
                                                             author,
                                                             title,
                                                             realization_place,
                                                             realization_date,
                                                             photo,
                                                             restorations,
                                                             loans,
                                                             income,
                                                             expense);

                            container.push_back(DeepPointer<Material>(picture));
                            delete picture;
                        }
                    }
                    else if (material_type == "Opera letteraria") {
                        bool complete = true, handwritten = true;
                        std::string language = "Sconosciuta", style = "Sconosciuto";

                        if (xmlReader.readNextStartElement() && xmlReader.name() == "completo")
                            complete = xmlReader.readElementText().toStdString() == "Si" ? true : false;
                        if (xmlReader.readNextStartElement() && xmlReader.name() == "manuale")
                            handwritten = xmlReader.readElementText().toStdString() == "Si" ? true : false;
                        if (xmlReader.readNextStartElement() && xmlReader.name() == "lingua")
                            language = xmlReader.readElementText().toStdString();
                        if (xmlReader.readNextStartElement() && xmlReader.name() == "stile")
                            style = xmlReader.readElementText().toStdString();

                        if (type == "Atto") {
                            std::string object = "Sconosciuto";

                            if (xmlReader.readNextStartElement() && xmlReader.name() == "oggetto")
                                object = xmlReader.readElementText().toStdString();

                            Material * act = new Act(sector,
                                                     base_value,
                                                     proprietary,
                                                     damaged,
                                                     available,
                                                     object,
                                                     complete,
                                                     handwritten,
                                                     language,
                                                     style,
                                                     author,
                                                     title,
                                                     realization_place,
                                                     realization_date,
                                                     photo,
                                                     restorations,
                                                     loans,
                                                     income,
                                                     expense);

                            container.push_back(DeepPointer<Material>(act));
                            delete act;
                        }
                        else if (type == "Lettera") {
                            std::string addressee = "Sconosciuto";

                            if (xmlReader.readNextStartElement() && xmlReader.name() == "destinatario")
                                addressee = xmlReader.readElementText().toStdString();

                            Material * letter = new Letter(sector,
                                                           base_value,
                                                           proprietary,
                                                           damaged,
                                                           available,
                                                           addressee,
                                                           complete,
                                                           handwritten,
                                                           language,
                                                           style,
                                                           author,
                                                           title,
                                                           realization_place,
                                                           realization_date,
                                                           photo,
                                                           restorations,
                                                           loans,
                                                           income,
                                                           expense);

                            container.push_back(DeepPointer<Material>(letter));
                            delete letter;
                        }
                    }
                }
                xmlReader.skipCurrentElement();
            }
        }
        else
            throw FileException("Errore durante la lettura del file!\nLa formattazione del file non è quella richiesta!");

        file.close();
    }
    else
        throw FileException("Errore durante l'apertura del file!\nCaricamento non eseguito!");

    return container;
}

void FileHandler::write(const Container<DeepPointer<Material>> & container) const {
    QSaveFile saveFile(QString::fromStdString(filePath));

    if (saveFile.open(QIODevice::WriteOnly)) {
        QXmlStreamWriter xmlWriter(&saveFile);

        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeComment("File generato automaticamente! Non modificare manualmente!");
        xmlWriter.writeStartElement("Materiali");

        Container<DeepPointer<Material>>::const_iterator c_it = container.cbegin();

        while (c_it != container.cend() && !xmlWriter.hasError()) {
            xmlWriter.writeStartElement("Materiale");

            xmlWriter.writeAttribute("tipo", QString::fromStdString(c_it->operator->()->getType()));
            xmlWriter.writeAttribute("tipoMateriale", QString::fromStdString(c_it->operator->()->getMaterialType()));

            xmlWriter.writeStartElement("settore");
            xmlWriter.writeCharacters(QString::fromStdString(std::to_string(c_it->operator->()->getSector())));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("valore");
            xmlWriter.writeCharacters(QString::fromStdString(Material::float_to_string(c_it->operator->()->getBaseValue())));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("privato");
            xmlWriter.writeCharacters(QString::fromStdString(c_it->operator->()->isProprietary() ? "Si" : "No"));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("danneggiato");
            xmlWriter.writeCharacters(QString::fromStdString(c_it->operator->()->isDamaged() ? "Si" : "No"));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("disponibile");
            xmlWriter.writeCharacters(QString::fromStdString(c_it->operator->()->isAvailable() ? "Si" : "No"));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("autore");
            xmlWriter.writeCharacters(QString::fromStdString(c_it->operator->()->getAuthor()));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("titolo");
            xmlWriter.writeCharacters(QString::fromStdString(c_it->operator->()->getTitle()));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("luogo");
            xmlWriter.writeCharacters(QString::fromStdString(c_it->operator->()->getPlace()));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("data");
            xmlWriter.writeCharacters(QString::fromStdString(c_it->operator->()->getDate()));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("foto");
            xmlWriter.writeCharacters(QString::fromStdString(c_it->operator->()->getPhoto()));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("restauri");
            xmlWriter.writeCharacters(QString::fromStdString(std::to_string(c_it->operator->()->getRestorations())));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("prestiti");
            xmlWriter.writeCharacters(QString::fromStdString(std::to_string(c_it->operator->()->getLoans())));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("entrate");
            xmlWriter.writeCharacters(QString::fromStdString(Material::float_to_string(c_it->operator->()->getIncome())));
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("uscite");
            xmlWriter.writeCharacters(QString::fromStdString(Material::float_to_string(c_it->operator->()->getExpense())));
            xmlWriter.writeEndElement();

            if (c_it->operator*().getMaterialType() == "Opera d'arte") {
                xmlWriter.writeStartElement("materiale");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<ArtWork *>(c_it->operator->())->getMaterial()));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("tecnica");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<ArtWork *>(c_it->operator->())->getTechnique()));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("movimento");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<ArtWork *>(c_it->operator->())->getArtMovement()));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("soggetto");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<ArtWork *>(c_it->operator->())->getSubject()));
                xmlWriter.writeEndElement();
            }
            else if (c_it->operator*().getMaterialType() == "Opera letteraria") {
                xmlWriter.writeStartElement("completo");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<LiteraryWork *>(c_it->operator->())->isComplete() ? "Si" : "No"));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("manuale");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<LiteraryWork *>(c_it->operator->())->isHandwritten() ? "Si" : "No"));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("lingua");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<LiteraryWork *>(c_it->operator->())->getLanguage()));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("stile");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<LiteraryWork *>(c_it->operator->())->getStyle()));
                xmlWriter.writeEndElement();
            }

            if (c_it->operator*().getType() == "Scultura") {
                xmlWriter.writeStartElement("forma");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<Sculpture *>(c_it->operator->())->getShape()));
                xmlWriter.writeEndElement();
            }
            else if (c_it->operator*().getType() == "Dipinto") {
                xmlWriter.writeStartElement("fotografia");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<Picture *>(c_it->operator->())->isPhotography() ? "Si" : "No"));
                xmlWriter.writeEndElement();
            }
            else if (c_it->operator*().getType() == "Atto") {
                xmlWriter.writeStartElement("oggetto");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<Act *>(c_it->operator->())->getObject()));
                xmlWriter.writeEndElement();
            }
            else if (c_it->operator*().getType() == "Lettera") {
                xmlWriter.writeStartElement("destinatario");
                xmlWriter.writeCharacters(QString::fromStdString(static_cast<Letter *>(c_it->operator->())->getAddressee()));
                xmlWriter.writeEndElement();
            }

            xmlWriter.writeEndElement();

            ++c_it;
        }

        if (xmlWriter.hasError())
            throw FileException("Errore durante la scrittura del file!\nAlcuni dati non sono stati salvati correttamente!");

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();

        saveFile.commit();
    }
    else
        throw FileException("Errore durante l'apertura del file!\nSalvataggio non eseguito!");
}

std::string FileHandler::getFilePath() const {
    return filePath;
}

void FileHandler::setFilePath(const std::string & filePath) {
    this->filePath = filePath;
}
