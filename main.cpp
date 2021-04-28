#include "mainwindow.h"
#include "graphwidget.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    w.show();

    GraphWidget graph;

    w.setCentralWidget(&graph);
    return a.exec();
}
