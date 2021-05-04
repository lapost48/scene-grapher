#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include "CircleGraph/circlegraph.h"

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>

#include <vector>


#include <Qt>


class GraphWidget : public QWidget
{
    Q_OBJECT

public:
    GraphWidget();
    ~GraphWidget();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    CircleGraph circles;

    bool leftPressed = false;
};

#endif // GRAPHWIDGET_H
