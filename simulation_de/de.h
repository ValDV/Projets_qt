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
    explicit De(int n = 0, QWidget *parent = nullptr);
    ~De();

    De& operator++();
    De operator++(int);
    De& operator=(int n);
    De& operator=(const De& other);
    De(const De& other);
    operator int() const;
    De& operator+=(int& n);

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
