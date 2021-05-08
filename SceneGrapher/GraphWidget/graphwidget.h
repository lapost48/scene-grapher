#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include "CircleGraph/circlegraph.h"
#include "graphmode.h"
#include "statemachine.h"

#include <Qt>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>

#include <vector>

class GraphWidget : public QWidget
{
    Q_OBJECT

public:
    GraphWidget();
    ~GraphWidget();

public slots:
    void toDefaultMode(bool);
    void toCreateMode(bool);
    void toMoveMode(bool);
    void toDeleteMode(bool);

signals:


protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    CircleGraph graph;
    StateMachine stateMachine;
};

#endif // GRAPHWIDGET_H
