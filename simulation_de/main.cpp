#include "de.h"
#include "dehisto.h"
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow mainWindow;
    QWidget *centralWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *buttonDe = new QPushButton("Lancer De", &mainWindow);
    QPushButton *buttonDehisto = new QPushButton("Lancer Dehisto", &mainWindow);

    layout->addWidget(buttonDe);
    layout->addWidget(buttonDehisto);

    mainWindow.setCentralWidget(centralWidget);
    mainWindow.show();

    QObject::connect(buttonDe, &QPushButton::clicked, [&]() {
        De *de = new De();
        de->show();
    });

    QObject::connect(buttonDehisto, &QPushButton::clicked, [&]() {
            static DeHisto *dehisto = new DeHisto();
            dehisto->show();
    });

    return a.exec();
}
