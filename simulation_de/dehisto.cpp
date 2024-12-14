#include "dehisto.h"
#include "ui_dehisto.h"
#include <QMessageBox>

Dehisto::Dehisto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dehisto)
{
    ui->setupUi(this);

    connect(ui->buttonSimuler, &QPushButton::clicked, this, &Dehisto::simulerPlusieursJets);
    connect(ui->buttonAfficher, &QPushButton::clicked, this, &Dehisto::afficherHistorique);
}

Dehisto::~Dehisto()
{
    delete ui;
}

void Dehisto::simulerPlusieursJets()
{
    ui->tableHistorique->clearContents();
    for (int i = 0; i < 6; ++i) {
        int valeur = rand() % 6 + 1;
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(valeur));
        ui->tableHistorique->setItem(i, 0, item);
    }
}

void Dehisto::afficherHistorique()
{
    QMessageBox::information(this, "Historique", "Voici l'historique des jets !");
}
