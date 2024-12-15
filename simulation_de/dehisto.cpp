#include "dehisto.h"
#include "ui_dehisto.h"
#include <QRandomGenerator>
#include <QTableWidgetItem>

DeHisto::DeHisto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeHisto)
    , derniereValeur(0)
{
    ui->setupUi(this);

    ui->tableHistorique->setColumnCount(1);
    ui->tableHistorique->setRowCount(6);
    ui->tableHistorique->setHorizontalHeaderLabels({"Valeurs"});
}

DeHisto::~DeHisto()
{
    delete ui;
}

void DeHisto::on_tireDe_clicked()
{
    derniereValeur = QRandomGenerator::global()->bounded(1, 7);
    historiqueDesLancers.append(derniereValeur);
    ui->labelValeurDe->setText(QString::number(derniereValeur));
}

void DeHisto::on_afficheValeurDe_clicked()
{
    ui->labelValeurDe->setText(QString::number(derniereValeur));
}

void DeHisto::on_nombreJets_clicked()
{
    historiqueDesLancers.clear();
    ui->tableHistorique->clearContents();

    for (int i = 0; i < 6; ++i) {
        int valeur = QRandomGenerator::global()->bounded(1, 7);
        historiqueDesLancers.append(valeur);

        QTableWidgetItem *item = new QTableWidgetItem(QString::number(valeur));
        ui->tableHistorique->setItem(i, 0, item);
    }
}

void DeHisto::on_historique_clicked()
{
    mettreAJourTableau();
}

void DeHisto::mettreAJourTableau()
{
    ui->tableHistorique->clearContents();
    ui->tableHistorique->setRowCount(historiqueDesLancers.size());

    for (int i = 0; i < historiqueDesLancers.size(); ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(historiqueDesLancers[i]));
        ui->tableHistorique->setItem(i, 0, item);
    }
}
