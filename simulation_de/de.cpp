#include "de.h"
#include "ui_de.h"
#include <cstdlib>
#include <ctime>

De::De(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::De)
{
    ui->setupUi(this);

    srand(static_cast<unsigned int>(time(0)));

    valeur = 0;
    score = 0;

    connect(ui->buttonAfficherValeur, &QPushButton::clicked, this, &De::afficherValeur);
    connect(ui->buttonTirerDe, &QPushButton::clicked, this, &De::tirerDe);
    connect(ui->buttonScoreTotal, &QPushButton::clicked, this, &De::ajouterScore);
    connect(ui->buttonRemettreZero, &QPushButton::clicked, this, &De::remettreZero);
}

De::~De()
{
    delete ui;
}

void De::afficherValeur() {
    ui->labelValeurDe->setText(QString::number(valeur));
}

void De::tirerDe() {
    valeur = rand() % 6 + 1;
    ui->labelValeurDe->setText(QString::number(valeur));
}

void De::ajouterScore() {

    score += valeur;
    ui->labelScoreTotal->setText(QString::number(score));
}

void De::remettreZero() {
    score = 0;
    ui->labelScoreTotal->setText("0");
}
