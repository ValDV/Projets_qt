#ifndef DE_H
#define DE_H

#include <QWidget>

namespace Ui {
class De;
}

class De : public QWidget
{
    Q_OBJECT

public:
    explicit De(QWidget *parent = nullptr);
    ~De();

private slots:
    void afficherValeur();
    void tirerDe();
    void ajouterScore();
    void remettreZero();

private:
    Ui::De *ui;
    int valeur;
    int score;
};

#endif
