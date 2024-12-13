#include "de.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    De dd;
    int n = 0;

    dd++;
    dd += n;
    dd = 0;

    De w;
    w.show();

    return a.exec();
}
