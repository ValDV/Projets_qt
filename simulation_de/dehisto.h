#ifndef DEHISTO_H
#define DEHISTO_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class DeHisto; }
QT_END_NAMESPACE

class DeHisto : public QMainWindow
{
    Q_OBJECT

public:
    DeHisto(QWidget *parent = nullptr);
    ~DeHisto();

private slots:
    void on_tireDe_clicked();
    void on_afficheValeurDe_clicked();
    void on_nombreJets_clicked();
    void on_historique_clicked();

private:
    Ui::DeHisto *ui;
    QVector<int> historiqueDesLancers;
    int derniereValeur;
    void mettreAJourTableau();
};
#endif
