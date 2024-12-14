#ifndef DEHISTO_H
#define DEHISTO_H

#include <QWidget>

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
    void simulerPlusieursJets();
    void afficherHistorique();

private:
    Ui::Dehisto *ui;
};

#endif
