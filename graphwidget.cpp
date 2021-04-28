#include "graphwidget.h"

#include <iostream>
#include <QPainter>

using namespace std;

GraphWidget::GraphWidget()
    : QWidget()
{
}

void GraphWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawEllipse(circleX,circleY,50,50);
}

void GraphWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        this->circleX = event->pos().x() - 25;
        this->circleY = event->pos().y() - 25;
        repaint();
        leftPressed = true;
    }
}

void GraphWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        leftPressed = false;
    }
}

void GraphWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(leftPressed)
    {
        this->circleX = event->pos().x() - 25;
        this->circleY = event->pos().y() - 25;
        repaint();
    }
}

GraphWidget::~GraphWidget()
{

}
