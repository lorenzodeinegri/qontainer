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

    firstDate->setDate(QDate(100, 1, 1));
    lastDate->setDate(QDate::currentDate());

    firstFloat->setText("0.0");
    lastFloat->setText("1000000000.0");

    firstInteger->setText("0");
    lastInteger->setText("100");

    trueRadio->setChecked(true);
    falseRadio->setChecked(false);
}

void Interact::setBoolsLabels(const QString & filter) const {
    if (filter == "Proprieta") {
        trueRadio->setText("Privato/a");
        falseRadio->setText("Pubblico/a");
        falseRadio->setCheckable(true);
    }
    else if (filter == "Stato") {
        trueRadio->setText("Danneggiato/a");
        falseRadio->setText("Integro/a");
        falseRadio->setCheckable(true);
    }
    else if (filter == "Disponibilita") {
        trueRadio->setText("Disponibile");
        falseRadio->setText("Inservibile");
        trueRadio->setCheckable(true);
    }
    else if (filter == "Testo") {
        trueRadio->setText("Completo/a");
        falseRadio->setText("Incompleto/a");
        trueRadio->setCheckable(true);
    }
    else if (filter == "Scrittura") {
        trueRadio->setText("Manoscritto");
        falseRadio->setText("Dattiloscritto");
        trueRadio->setCheckable(true);
    }
    else if (filter == "Formato") {
        trueRadio->setText("Fotografia");
        falseRadio->setText("Rappresentazione");
        falseRadio->setCheckable(true);
    }
}

void Interact::search(const QString & filter) {
    hideAll();
    resetAll();

    if (filter == "Data") {
        setLabelsVisibility(true);
        setDatesVisibility(true);

        emit searchDates(firstDate->date(), lastDate->date());
    }
    else if (filter == "Valore Base" || filter == "Entrate" || filter == "Uscite") {
        setLabelsVisibility(true);
        setFloatsVisibility(true);

        emit searchFloats(firstFloat->text().toFloat(), lastFloat->text().toFloat());
    }
    else if (filter == "Restauri" || filter == "Prestiti") {
        setLabelsVisibility(true);
        setIntegersVisibility(true);

        emit searchIntegers(firstFloat->text().toUInt(), lastFloat->text().toUInt());
    }
    else if (filter == "Proprieta" || filter == "Stato" || filter == "Disponibilita" || filter == "Testo" || filter == "Scrittura" || filter == "Formato") {
        setBoolsLabels(filter);
        setBoolsVisibility(true);

        emit searchBools(trueRadio->isChecked());
    }
    else {
        searchEdit->setVisible(true);

        if (filter == "Settore")
            searchEdit->setValidator(new QIntValidator(1, 100, this));
        else
            searchEdit->setValidator(nullptr);

        emit searchRegularExpressions(searchEdit->text());
    }
}

void Interact::searchExpressions(const QString & regularExpression) const {
    emit searchRegularExpressions(regularExpression);
}

void Interact::searchDates() const {
    emit searchDates(firstDate->date(), lastDate->date());
}

void Interact::searchFloats() const {
    emit searchFloats(firstFloat->text().toFloat(), lastFloat->text().toFloat());
}

void Interact::searchIntegers() const {
    emit searchIntegers(firstInteger->text().toUInt(), lastInteger->text().toUInt());
}

void Interact::searchBools() const {
    emit searchBools(trueRadio->isChecked());
}

void Interact::details() const {
    emit details(list->selectionModel()->selectedIndexes());
}

void Interact::modifies() const {
    emit modifies(list->selectionModel()->selectedIndexes());
}

void Interact::restore() const {
    emit restore(list->selectionModel()->selectedIndexes());
}

void Interact::lend() const {
    emit lend(list->selectionModel()->selectedIndexes());
}

void Interact::calculateValue() const {
    emit calculateValue(list->selectionModel()->selectedIndexes());
}

void Interact::calculateProfit() const {
    emit calculateProfit(list->selectionModel()->selectedIndexes());
}

void Interact::calculateIncome() const {
    emit calculateIncome(list->selectionModel()->selectedIndexes());
}

void Interact::calculateExpense() const {
    emit calculateExpense(list->selectionModel()->selectedIndexes());
}

void Interact::deletes() const {
    emit deletes(list->selectionModel()->selectedIndexes());
}

void Interact::reset() const {
    hideAll();
    resetAll();

    searchComboBox->setCurrentIndex(1);
    searchComboBox->setCurrentIndex(0);
}

Interact::Interact(List * list, SearchComboBox * searchComboBox, QWidget * parent) :
    QWidget(parent),
    list(list),
    searchComboBox(searchComboBox),
    searchEdit(new QLineEdit("", this)),
    first(new QLabel("Primo:", this)),
    last(new QLabel("Ultimo:", this)),
    firstDate(new QDateEdit(QDate(), this)),
    lastDate(new QDateEdit(QDate(), this)),
    firstFloat(new QLineEdit("0.0", this)),
    lastFloat(new QLineEdit("1000000000.0", this)),
    firstInteger(new QLineEdit("1", this)),
    lastInteger(new QLineEdit("100", this)),
    trueRadio(new QRadioButton("", this)),
    falseRadio(new QRadioButton("", this))
{
    searchEdit->setPlaceholderText("Cerca...");

    firstFloat->setPlaceholderText("Minimo...");
    lastFloat->setPlaceholderText("Massimo...");

    firstInteger->setPlaceholderText("Minimo...");
    lastInteger->setPlaceholderText("Massimo...");

    firstDate->setMinimumDate(QDate(100, 1, 1));
    lastDate->setMinimumDate(QDate(100, 1, 1));

    firstDate->setMaximumDate(QDate::currentDate());
    lastDate->setMaximumDate(QDate::currentDate());

    firstDate->setDisplayFormat("dd/MM/yyyy");
    lastDate->setDisplayFormat("dd/MM/yyyy");

    firstDate->setDate(QDate(100, 1, 1));
    lastDate->setDate(QDate::currentDate());

    QButtonGroup * buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(trueRadio, 1);
    buttonGroup->addButton(falseRadio, 2);

    QVBoxLayout * mainForm = new QVBoxLayout(this);

    QVBoxLayout * topForm = new QVBoxLayout();
    QHBoxLayout * middleForm = new QHBoxLayout();

    QVBoxLayout * listForm = new QVBoxLayout();
    QVBoxLayout * buttonsForm = new QVBoxLayout();

    QHBoxLayout * searchForm = new QHBoxLayout();
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

    listForm->addWidget(list);

    QHBoxLayout * search = new QHBoxLayout();
    QPushButton * resetButton = new QPushButton("Cancella", this);
    resetButton->setToolTip("Resetta i filtri di ricerca");
    resetButton->setToolTipDuration(-1);
    search->addWidget(searchComboBox);
    search->addWidget(resetButton);

    QHBoxLayout * shows = new QHBoxLayout();
    QPushButton * modifiesButton = new QPushButton("Modifica", this);
    modifiesButton->setToolTip("Mostra la finestra di modifica per il materiale selezionato");
    modifiesButton->setToolTipDuration(-1);
    QPushButton * detailsButton = new QPushButton("Visualizza", this);
    detailsButton->setToolTip("Mostra la finestra di visualizzazione per il materiale selezionato");
    detailsButton->setToolTipDuration(-1);
    shows->addWidget(modifiesButton);
    shows->addWidget(detailsButton);

    QHBoxLayout * operations = new QHBoxLayout();
    QPushButton * restoreButton = new QPushButton("Restaura", this);
    restoreButton->setToolTip("Manda in restauro il materiale selezionato");
    restoreButton->setToolTipDuration(-1);
    QPushButton * lendButton = new QPushButton("Presta", this);
    lendButton->setToolTip("Manda in prestito il materiale selezionato");
    lendButton->setToolTipDuration(-1);
    operations->addWidget(restoreButton);
    operations->addWidget(lendButton);

    QHBoxLayout * calculatePlus = new QHBoxLayout();
    QPushButton * valueButton = new QPushButton("Valore", this);
    valueButton->setToolTip("Calcola il valore del materiale selezionato");
    valueButton->setToolTipDuration(-1);
    QPushButton * profitButton = new QPushButton("Profitto", this);
    profitButton->setToolTip("Calcola il profitto per materiale selezionato");
    profitButton->setToolTipDuration(-1);
    calculatePlus->addWidget(valueButton);
    calculatePlus->addWidget(profitButton);

    QHBoxLayout * calculateMinus = new QHBoxLayout();
    QPushButton * incomeButton = new QPushButton("Entrate", this);
    incomeButton->setToolTip("Calcola le entrate per materiale selezionato");
    incomeButton->setToolTipDuration(-1);
    QPushButton * expenseButton = new QPushButton("Uscite", this);
    expenseButton->setToolTip("Calcola le uscite per materiale selezionato");
    expenseButton->setToolTipDuration(-1);
    calculateMinus->addWidget(incomeButton);
    calculateMinus->addWidget(expenseButton);

    QHBoxLayout * calculateTotalPlus = new QHBoxLayout();
    QPushButton * totalValueButton = new QPushButton("Valore Totale", this);
    totalValueButton->setToolTip("Calcola il valore totale dei materiali visualizzati");
    totalValueButton->setToolTipDuration(-1);
    QPushButton * totalProfitButton = new QPushButton("Profitto Totale", this);
    totalProfitButton->setToolTip("Calcola il profitto totale per i materiali visualizzati");
    totalProfitButton->setToolTipDuration(-1);
    calculateTotalPlus->addWidget(totalValueButton);
    calculateTotalPlus->addWidget(totalProfitButton);

    QHBoxLayout * calculateTotalMinus = new QHBoxLayout();
    QPushButton * totalIncomeButton = new QPushButton("Entrate Totali", this);
    totalIncomeButton->setToolTip("Calcola le entrate totali per i materiali visualizzati");
    totalIncomeButton->setToolTipDuration(-1);
    QPushButton * totalExpenseButton = new QPushButton("Uscite Totali", this);
    totalExpenseButton->setToolTip("Calcola le uscite totali per i materiali visualizzati");
    totalExpenseButton->setToolTipDuration(-1);
    calculateTotalMinus->addWidget(totalIncomeButton);
    calculateTotalMinus->addWidget(totalExpenseButton);

    QPushButton * deleteButton = new QPushButton("Rimuovi", this);
    deleteButton->setToolTip("Rimuovi il materiale selezionato");
    deleteButton->setToolTipDuration(-1);

    buttonsForm->addLayout(shows);
    buttonsForm->addLayout(operations);
    buttonsForm->addLayout(calculatePlus);
    buttonsForm->addLayout(calculateMinus);
    buttonsForm->addLayout(calculateTotalPlus);
    buttonsForm->addLayout(calculateTotalMinus);
    buttonsForm->addWidget(deleteButton);

    middleForm->addLayout(listForm);
    middleForm->addLayout(buttonsForm);

    topForm->addLayout(search);
    topForm->addLayout(searchForm);

    mainForm->addLayout(topForm);
    mainForm->addLayout(middleForm);

    setLayout(mainForm);

    connect(searchComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(search(const QString &)));
    connect(searchEdit, SIGNAL(textChanged(const QString &)), this, SLOT(searchExpressions(const QString &)));
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

    connect(totalValueButton, SIGNAL(clicked()), this, SIGNAL(calculateTotalValue()));
    connect(totalProfitButton, SIGNAL(clicked()), this, SIGNAL(calculateTotalProfit()));
    connect(totalIncomeButton, SIGNAL(clicked()), this, SIGNAL(calculateTotalIncome()));
    connect(totalExpenseButton, SIGNAL(clicked()), this, SIGNAL(calculateTotalExpense()));

    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deletes()));

    connect(resetButton, SIGNAL(clicked()), this, SLOT(reset()));

    reset();
}

QSize Interact::sizeHint() const {
    return QSize(1050, 500);
}
