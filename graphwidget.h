#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <QMouseEvent>

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
    int circleX;
    int circleY;

    bool leftPressed = false;
};

#endif // GRAPHWIDGET_H
