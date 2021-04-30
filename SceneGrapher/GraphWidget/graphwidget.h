#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include "CircleGraph/circlegraph.h"
#include "Locator/locator.h"

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

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    CircleGraph circles;
    Locator locator;

    bool leftPressed = false;
};

#endif // GRAPHWIDGET_H
