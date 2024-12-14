#include "de.h"
#include "ui_de.h"
#include <cstdlib>
#include <ctime>

De::De(int n, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::De),
    valeur(0),
    score(0)
{
    ui->setupUi(this);

    srand(static_cast<unsigned int>(time(0)));

    if (n > 0) {
        valeur = n;
    }

    connect(ui->buttonAfficherValeur, &QPushButton::clicked, this, &De::afficherValeur);
    connect(ui->buttonTirerDe, &QPushButton::clicked, this, &De::tirerDe);
    connect(ui->buttonScoreTotal, &QPushButton::clicked, this, &De::ajouterScore);
    connect(ui->buttonRemettreZero, &QPushButton::clicked, this, &De::remettreZero);
}

De::~De()
{
    delete ui;
}

De::De(const De& other) :
    ui(new Ui::De),
    valeur(other.valeur),
    score(other.score)
{
    ui->setupUi(this);
}


De& De::operator=(const De& other) {
    if (this != &other) {
        valeur = other.valeur;
        score = other.score;
    }
    return *this;
}

void De::afficherValeur() {
    ui->labelValeurDe->setText(QString::number(valeur));
}

void De::tirerDe() {
    valeur = rand() % 6 + 1;
    ui->labelValeurDe->setText(QString::number(valeur));
    score += valeur;
}

void De::ajouterScore() {
    ui->labelScoreTotal->setText(QString::number(score));
}

void De::remettreZero() {
    score = 0;
    ui->labelScoreTotal->setText("0");
}


De& De::operator++() {
    valeur = rand() % 6 + 1;
    return *this;
}

De De::operator++(int) {
    De temp = *this;
    valeur = rand() % 6 + 1;
    return temp;
}

De& De::operator=(int n) {
    valeur = n;
    return *this;
}

De::operator int() const {
    return valeur;
}

De& De::operator+=(int& n) {

    n += valeur;
    return *this;
}
