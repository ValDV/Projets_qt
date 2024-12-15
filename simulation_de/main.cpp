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

    QPushButton *buttonDe = new QPushButton("de", &mainWindow);
    QPushButton *buttonDehisto = new QPushButton("dehisto", &mainWindow);

    layout->addWidget(buttonDe);
    layout->addWidget(buttonDehisto);

    mainWindow.setCentralWidget(centralWidget);
    mainWindow.show();

    QObject::connect(buttonDe, &QPushButton::clicked, [&]() {
        De *de = new De();
        de->show();
    });

    QObject::connect(buttonDehisto, &QPushButton::clicked, [&]() {
        static Dehisto *dehisto = new Dehisto();
        dehisto->show();
    });

    return a.exec();
}
