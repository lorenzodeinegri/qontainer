#include "menu.h"

Menu::Menu(QWidget * parent) : QMenuBar(parent) {
    // Costruzione dei componenti del menu
    QMenu * file = new QMenu("File", this);
    QMenu * help = new QMenu("Help", this);

    QAction * load = new QAction("Carica", file);
    QAction * save = new QAction("Salva", file);
    QAction * saveName = new QAction("Salva con Nome", file);
    QAction * exit = new QAction("Esci", file);
    QAction * insert = new QAction("&Inserisci", this);
    QAction * interact = new QAction("I&nteragisci", this);
    QAction * about = new QAction("About", help);

    load->setStatusTip("Carica dati da file");
    load->setShortcut(QKeySequence::Open);
    save->setStatusTip("Salva i dati correnti su file");
    save->setShortcut(QKeySequence::Save);
    saveName->setStatusTip("Salva i dati correnti sul file specificato");
    saveName->setShortcut(QKeySequence::SaveAs);
    exit->setStatusTip("Chiudi l'applicazione");
    exit->setShortcut(QKeySequence::Close);

    insert->setStatusTip("Mostra la finestra di inserimento dati");
    insert->setShortcut(QKeySequence("ctrl+i"));

    interact->setStatusTip("Mostra la finestra di interazione con i dati inseriti");
    interact->setShortcut(QKeySequence("ctrl+alt+i"));

    about->setStatusTip("Mostra le informazione sull'applicazione");
    about->setShortcut(QKeySequence::WhatsThis);

    // Assemblaggio del menu
    file->addAction(load);
    file->addAction(save);
    file->addAction(saveName);
    file->addAction(exit);

    help->addAction(about);

    addMenu(file);
    addAction(insert);
    addAction(interact);
    addMenu(help);

    // Connect per la gestione del click sui componenti del menu
    connect(load, SIGNAL(triggered()), this, SIGNAL(load()));
    connect(save, SIGNAL(triggered()), this, SIGNAL(save()));
    connect(saveName, SIGNAL(triggered()), this, SIGNAL(saveName()));
    connect(exit, SIGNAL(triggered()), this, SIGNAL(exit()));
    connect(insert, SIGNAL(triggered()), this, SIGNAL(insert()));
    connect(interact, SIGNAL(triggered()), this, SIGNAL(interact()));
    connect(about, SIGNAL(triggered()), this, SIGNAL(about()));
}
