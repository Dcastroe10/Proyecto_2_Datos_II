#include "mainwindow.h"

#include <QApplication>

#include "DataStructures/linkedlist.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    linkedList lista;
    lista.addCoords(2, 3);
    lista.addCoords(5, 3);

    qDebug() << lista.getCoords(0)[0] << lista.getCoords(0)[1] << lista.getCoords(1)[0]<< lista.getCoords(1)[1];

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
