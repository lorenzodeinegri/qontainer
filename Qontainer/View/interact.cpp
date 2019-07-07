#include "interact.h"

void Interact::setLabelsVisibility(bool visibility) const {
    first->setVisible(visibility);
    last->setVisible(visibility);
}

void Interact::setDatesVisibility(bool visibility) const{
    firstDate->setVisible(visibility);
    lastDate->setVisible(visibility);
}

void Interact::setFloatsVisibility(bool visibility) const {
    firstFloat->setVisible(visibility);
    lastFloat->setVisible(visibility);
}

void Interact::setIntegersVisibility(bool visibility) const {
    firstInteger->setVisible(visibility);
    lastInteger->setVisible(visibility);
}

void Interact::setBoolsVisibility(bool visibility) const {
    trueRadio->setVisible(visibility);
    falseRadio->setVisible(visibility);
}

void Interact::hideAll() const {
    searchEdit->setVisible(false);
    setLabelsVisibility(false);
    setDatesVisibility(false);
    setFloatsVisibility(false);
    setIntegersVisibility(false);
    setBoolsVisibility(false);
}

void Interact::resetAll() const {
    searchEdit->setValidator(nullptr);
    searchEdit->setText("");

    firstDate->setDate(QDate::fromString("00/00/0000", "dd/MM/yyyy"));
    lastDate->setDate(QDate::fromString("00/00/0000", "dd/MM/yyyy"));

    firstFloat->setText("0.0");
    lastFloat->setText("0.0");

    firstInteger->setText("0");
    lastInteger->setText("0");

    trueRadio->setChecked(true);
    falseRadio->setChecked(false);
}

void Interact::setBoolsLabels(const QString & filter) const {
    if (filter == "Proprieta") {
        trueRadio->setText("Privato/a");
        falseRadio->setText("Pubblico/a");
    }
    else if (filter == "Stato") {
        trueRadio->setText("Danneggiato/a");
        falseRadio->setText("Integro/a");
    }
    else if (filter == "Disponibilita") {
        trueRadio->setText("Disponibile");
        falseRadio->setText("Inservibile");
    }
    else if (filter == "Testo") {
        trueRadio->setText("Completo/a");
        falseRadio->setText("Incompleto/a");
    }
    else if (filter == "Scrittura") {
        trueRadio->setText("Manoscritto");
        falseRadio->setText("Dattiloscritto");
    }
    else if (filter == "Formato") {
        trueRadio->setText("Fotografia");
        falseRadio->setText("Rappresentazione");
    }
}

void Interact::search(const QString & filter) const {
    hideAll();
    resetAll();

    if (filter == "Data") {
        setLabelsVisibility(true);
        setDatesVisibility(true);

        emit searchDates(firstDate->date(), lastDate->date(), filter);
    }
    else if (filter == "Restauri" || filter == "Prestiti") {
        setLabelsVisibility(true);
        setFloatsVisibility(true);

        emit searchFloats(firstFloat->text().toFloat(), lastFloat->text().toFloat(), filter);
    }
    else if (filter == "Valore Base" || filter == "Entrate" || filter == "Uscite") {
        setLabelsVisibility(true);
        setIntegersVisibility(true);

        emit searchIntegers(firstFloat->text().toUInt(), lastFloat->text().toUInt(), filter);
    }
    else if (filter == "Proprieta" || filter == "Stato" || filter == "Disponibilita" || filter == "Testo" || filter == "Scrittura" || filter == "Formato") {
        setBoolsLabels(filter);
        setBoolsVisibility(true);

        emit searchBools(trueRadio->isChecked(), filter);
    }
    else {
        searchEdit->setVisible(true);

        if (filter == "Settore")
            searchEdit->setValidator(new QIntValidator(1, 100));
        else
            searchEdit->setValidator(nullptr);

        emit searchRegularExpressions(searchEdit->text(), filter);
    }
}

void Interact::searchRegularExpressions(const QString & regularExpression) const {
    emit searchRegularExpressions(regularExpression, searchComboBox->currentText());
}

void Interact::searchDates() const {
    emit searchDates(firstDate->date(), lastDate->date(), searchComboBox->currentText());
}

void Interact::searchFloats() const {
    emit searchFloats(firstFloat->text().toFloat(), lastFloat->text().toFloat(), searchComboBox->currentText());
}

void Interact::searchIntegers() const {
    emit searchIntegers(firstInteger->text().toUInt(), lastInteger->text().toUInt(), searchComboBox->currentText());
}

void Interact::searchBools() const {
    emit searchBools(trueRadio->isChecked(), searchComboBox->currentText());
}

void Interact::details() const {
    emit details(list->selectionModel()->selectedIndexes().first());
}

void Interact::modifies() const {
    emit modifies(list->selectionModel()->selectedIndexes().first());
}

void Interact::restore() const {
    emit restore(list->selectionModel()->selectedIndexes().first());
}

void Interact::lend() const {
    emit lend(list->selectionModel()->selectedIndexes().first());
}

void Interact::calculateValue() const {
    emit calculateValue(list->selectionModel()->selectedIndexes().first());
}

void Interact::calculateProfit() const {
    emit calculateProfit(list->selectionModel()->selectedIndexes().first());
}

void Interact::calculateIncome() const {
    emit calculateIncome(list->selectionModel()->selectedIndexes().first());
}

void Interact::calculateExpense() const {
    emit calculateExpense(list->selectionModel()->selectedIndexes().first());
}

void Interact::calculateTotalValue() const {
    list->selectAll();
    QModelIndexList indexes = list->selectionModel()->selectedIndexes();
    list->clearSelection();
    emit calculateTotalValue(indexes);
}

void Interact::calculateTotalProfit() const {
    list->selectAll();
    QModelIndexList indexes = list->selectionModel()->selectedIndexes();
    list->clearSelection();
    emit calculateTotalProfit(indexes);
}

void Interact::calculateTotalIncome() const {
    list->selectAll();
    QModelIndexList indexes = list->selectionModel()->selectedIndexes();
    list->clearSelection();
    emit calculateTotalIncome(indexes);
}

void Interact::calculateTotalExpense() const {
    list->selectAll();
    QModelIndexList indexes = list->selectionModel()->selectedIndexes();
    list->clearSelection();
    emit calculateTotalExpense(indexes);
}

void Interact::deletes() const {
    emit deletes(list->selectionModel()->selectedIndexes().first());
}

void Interact::reset() const {
    hideAll();
    resetAll();

    searchComboBox->setCurrentIndex(0);
}

Interact::Interact(List * list, QWidget * parent) :
    QWidget(parent),
    list(list),
    searchComboBox(new SearchComboBox(this)),
    searchEdit(new QLineEdit("", this)),
    first(new QLabel("Primo:", this)),
    last(new QLabel("Ultimo:", this)),
    firstDate(new QDateEdit(QDate::fromString("00/00/0000", "dd/MM/yyyy"), this)),
    lastDate(new QDateEdit(QDate::fromString("00/00/0000", "dd/MM/yyyy"), this)),
    firstFloat(new QLineEdit("0.0", this)),
    lastFloat(new QLineEdit("0.0", this)),
    firstInteger(new QLineEdit("0", this)),
    lastInteger(new QLineEdit("0", this)),
    trueRadio(new QRadioButton("", this)),
    falseRadio(new QRadioButton("", this))
{
    QHBoxLayout * mainForm = new QHBoxLayout(this);

    QVBoxLayout * listForm = new QVBoxLayout(this);
    QVBoxLayout * buttonsForm = new QVBoxLayout(this);

    QHBoxLayout * searchForm = new QHBoxLayout(this);
    searchForm->addWidget(searchEdit);
    searchForm->addWidget(first);
    searchForm->addWidget(firstDate);
    searchForm->addWidget(firstFloat);
    searchForm->addWidget(firstInteger);
    searchForm->addWidget(last);
    searchForm->addWidget(lastDate);
    searchForm->addWidget(lastFloat);
    searchForm->addWidget(lastInteger);
    searchForm->addWidget(trueRadio);
    searchForm->addWidget(falseRadio);

    listForm->addLayout(searchForm);
    listForm->addWidget(list);

    QHBoxLayout * search = new QHBoxLayout(this);
    QPushButton * resetButton = new QPushButton("Cancella", this);
    resetButton->setToolTip("Resetta i filtri di ricerca");
    resetButton->setToolTipDuration(-1);
    search->addWidget(searchComboBox);
    search->addWidget(resetButton);

    QHBoxLayout * shows = new QHBoxLayout(this);
    QPushButton * modifiesButton = new QPushButton("Modifica", this);
    modifiesButton->setToolTip("Mostra la finestra di modifica per il materiale selezionato");
    modifiesButton->setToolTipDuration(-1);
    QPushButton * detailsButton = new QPushButton("Visualizza", this);
    detailsButton->setToolTip("Mostra la finestra di visualizzazione per il materiale selezionato");
    detailsButton->setToolTipDuration(-1);
    shows->addWidget(modifiesButton);
    shows->addWidget(detailsButton);

    QHBoxLayout * operations = new QHBoxLayout(this);
    QPushButton * restoreButton = new QPushButton("Restaura", this);
    restoreButton->setToolTip("Manda in restauro il materiale selezionato");
    restoreButton->setToolTipDuration(-1);
    QPushButton * lendButton = new QPushButton("Presta", this);
    lendButton->setToolTip("Manda in prestito il materiale selezionato");
    lendButton->setToolTipDuration(-1);
    shows->addWidget(restoreButton);
    shows->addWidget(lendButton);

    QHBoxLayout * calculatePlus = new QHBoxLayout(this);
    QPushButton * valueButton = new QPushButton("Calcola Valore", this);
    valueButton->setToolTip("Calcola il valore del materiale selezionato");
    valueButton->setToolTipDuration(-1);
    QPushButton * profitButton = new QPushButton("Calcola Profitto", this);
    profitButton->setToolTip("Calcola il profitto per materiale selezionato");
    profitButton->setToolTipDuration(-1);
    shows->addWidget(valueButton);
    shows->addWidget(profitButton);

    QHBoxLayout * calculateMinus = new QHBoxLayout(this);
    QPushButton * incomeButton = new QPushButton("Calcola Entrate", this);
    incomeButton->setToolTip("Calcola le entrate per materiale selezionato");
    incomeButton->setToolTipDuration(-1);
    QPushButton * expenseButton = new QPushButton("Calcola Uscite", this);
    expenseButton->setToolTip("Calcola le uscite per materiale selezionato");
    expenseButton->setToolTipDuration(-1);
    shows->addWidget(incomeButton);
    shows->addWidget(expenseButton);

    QHBoxLayout * calculateTotalPlus = new QHBoxLayout(this);
    QPushButton * totalValueButton = new QPushButton("Calcola Valore Totale", this);
    totalValueButton->setToolTip("Calcola il valore totale dei materiali visualizzati");
    totalValueButton->setToolTipDuration(-1);
    QPushButton * totalProfitButton = new QPushButton("Calcola Profitto Totale", this);
    totalProfitButton->setToolTip("Calcola il profitto totale per i materiali visualizzati");
    totalProfitButton->setToolTipDuration(-1);
    shows->addWidget(totalValueButton);
    shows->addWidget(totalProfitButton);

    QHBoxLayout * calculateTotalMinus = new QHBoxLayout(this);
    QPushButton * totalIncomeButton = new QPushButton("Calcola Entrate Totali", this);
    totalIncomeButton->setToolTip("Calcola le entrate totali per i materiali visualizzati");
    totalIncomeButton->setToolTipDuration(-1);
    QPushButton * totalExpenseButton = new QPushButton("Calcola Uscite Totali", this);
    totalExpenseButton->setToolTip("Calcola le uscite totali per i materiali visualizzati");
    totalExpenseButton->setToolTipDuration(-1);
    shows->addWidget(totalIncomeButton);
    shows->addWidget(totalExpenseButton);

    QPushButton * deleteButton = new QPushButton("Elimina", this);
    deleteButton->setToolTip("Elimina il materiale selezionato");
    deleteButton->setToolTipDuration(-1);

    buttonsForm->addLayout(search);
    buttonsForm->addLayout(shows);
    buttonsForm->addLayout(operations);
    buttonsForm->addLayout(calculatePlus);
    buttonsForm->addLayout(calculateMinus);
    buttonsForm->addLayout(calculateTotalPlus);
    buttonsForm->addLayout(calculateTotalMinus);
    buttonsForm->addWidget(deleteButton);

    mainForm->addLayout(listForm);
    mainForm->addLayout(buttonsForm);

    setLayout(mainForm);

    connect(searchComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(search(const QString &)));
    connect(searchEdit, SIGNAL(textChanged(const QString &)), this, SLOT(searchRegularExpressions(const QString &)));
    connect(firstDate, SIGNAL(dateChanged(const QDate &)), this, SLOT(searchDates()));
    connect(lastDate, SIGNAL(dateChanged(const QDate &)), this, SLOT(searchDates()));
    connect(firstFloat, SIGNAL(textChanged(const QString &)), this, SLOT(searchFloats()));
    connect(lastFloat, SIGNAL(textChanged(const QString &)), this, SLOT(searchFloats()));
    connect(firstInteger, SIGNAL(textChanged(const QString &)), this, SLOT(searchIntegers()));
    connect(lastInteger, SIGNAL(textChanged(const QString &)), this, SLOT(searchIntegers()));
    connect(trueRadio, SIGNAL(toggled(bool)), this, SLOT(searchBools()));
    connect(falseRadio, SIGNAL(toggled(bool)), this, SLOT(searchBools()));

    connect(detailsButton, SIGNAL(clicked()), this, SLOT(details()));
    connect(modifiesButton, SIGNAL(clicked()), this, SLOT(modifies()));

    connect(restoreButton, SIGNAL(clicked()), this, SLOT(restore()));
    connect(lendButton, SIGNAL(clicked()), this, SLOT(lend()));

    connect(valueButton, SIGNAL(clicked()), this, SLOT(calculateValue()));
    connect(profitButton, SIGNAL(clicked()), this, SLOT(calculateProfit()));
    connect(incomeButton, SIGNAL(clicked()), this, SLOT(calculateIncome()));
    connect(expenseButton, SIGNAL(clicked()), this, SLOT(calculateExpense()));

    connect(totalValueButton, SIGNAL(clicked()), this, SLOT(calculateTotalValue()));
    connect(totalProfitButton, SIGNAL(clicked()), this, SLOT(calculateTotalProfit()));
    connect(totalIncomeButton, SIGNAL(clicked()), this, SLOT(calculateTotalIncome()));
    connect(totalExpenseButton, SIGNAL(clicked()), this, SLOT(calculateTotalExpense()));

    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deletes()));

    connect(resetButton, SIGNAL(clicked()), this, SLOT(reset()));

    reset();
}
