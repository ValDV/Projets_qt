#include "dehisto.h"
#include "ui_dehisto.h"
#include <cstdlib>
#include <ctime>
#include <QTableWidgetItem>

Dehisto::Dehisto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dehisto),
    valeurDe(0),
    nombreJets(0)
{
    ui->setupUi(this);

    this->setWindowTitle("dehisto");

    connect(ui->buttonTirerDe, &QPushButton::clicked, this, &Dehisto::tirerDe);
    connect(ui->buttonAfficherValeur, &QPushButton::clicked, this, &Dehisto::afficherValeurDe);
    connect(ui->buttonNombreJets, &QPushButton::clicked, this, &Dehisto::simulerNombreJets);
    connect(ui->buttonHistorique, &QPushButton::clicked, this, &Dehisto::afficherHistorique);

    ui->tableHistorique->setColumnCount(2);
    QStringList headers = {"Indice", "Valeurs"};
    ui->tableHistorique->setHorizontalHeaderLabels(headers);

    std::srand(std::time(nullptr));
}

Dehisto::~Dehisto()
{
    delete ui;
}

void Dehisto::tirerDe()
{
    valeurDe = std::rand() % 6 + 1;
    historique.append(valeurDe);
}

void Dehisto::afficherValeurDe()
{
    ui->labelValeurDe->setText(QString::number(valeurDe));
}

void Dehisto::simulerNombreJets()
{
    nombreJets = 6;
    historique.clear();
    for (int i = 0; i < nombreJets; ++i) {
        int valeur = std::rand() % 6 + 1;
        historique.append(valeur);
    }
    ui->labelNombreJets->setText(QString::number(nombreJets));
}

void Dehisto::afficherHistorique()
{
    ui->tableHistorique->clearContents();
    ui->tableHistorique->setRowCount(historique.size());
    for (int i = 0; i < historique.size(); ++i) {
        QTableWidgetItem *indiceItem = new QTableWidgetItem(QString::number(i + 1));
        QTableWidgetItem *valeurItem = new QTableWidgetItem(QString::number(historique[i]));
        ui->tableHistorique->setItem(i, 0, indiceItem);
        ui->tableHistorique->setItem(i, 1, valeurItem);
    }
}
