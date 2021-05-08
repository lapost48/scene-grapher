#include "mainwindow.h"
#include "GraphWidget/graphwidget.h"

#include <QApplication>
#include <QToolBar>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    w.show();

    GraphWidget graph;
    QToolBar toolbar;

    QAction* createAction = toolbar.addAction("Create", &graph, SLOT(toCreateMode(bool)));
    QAction*   moveAction = toolbar.addAction("Move",   &graph, SLOT(  toMoveMode(bool)));
    QAction* deleteAction = toolbar.addAction("Delete", &graph, SLOT(toDeleteMode(bool)));

    w.setCentralWidget(&graph);
    w.addToolBar(&toolbar);
    return a.exec();
}
