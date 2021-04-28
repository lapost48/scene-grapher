#include "graphwidget.h"


GraphWidget::GraphWidget()
    : QWidget()
{
}

GraphWidget::~GraphWidget()
{
}

void GraphWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    for (int i = 0; i < circleX.size(); i++)
    {
        p.drawEllipse(circleX[i],circleY[i],50,50);
    }
}

void GraphWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        this->circleX.push_back(event->pos().x() - 25);
        this->circleY.push_back(event->pos().y() - 25);
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
        this->circleX.pop_back();
        this->circleY.pop_back();
        this->circleX.push_back(event->pos().x() - 25);
        this->circleY.push_back(event->pos().y() - 25);
        repaint();
    }
}
