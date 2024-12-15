#ifndef DEHISTO_H
#define DEHISTO_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class Dehisto;
}

class Dehisto : public QWidget
{
    Q_OBJECT

public:
    explicit Dehisto(QWidget *parent = nullptr);
    ~Dehisto();

private slots:
    void tirerDe();
    void afficherValeurDe();
    void simulerNombreJets();
    void afficherHistorique();

private:
    Ui::Dehisto *ui;
    int valeurDe;
    int nombreJets;
    QList<int> historique;
};

#endif
