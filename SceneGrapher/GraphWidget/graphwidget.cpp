#include "graphwidget.h"


GraphWidget::GraphWidget()
    : QWidget(), locator(&circles)
{

}

GraphWidget::~GraphWidget()
{
}

void GraphWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    for (int i = 0; i < circles.getSize(); i++)
    {
        CircleNode* node = circles.get(i);
        p.drawEllipse(node->getX(), node->getY(), node->getSize(), node->getSize());
    }
}

void GraphWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        int x = event->pos().x() - 25;
        int y = event->pos().y() - 25;
        circles.add(new CircleNode(x, y, 50));
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
        int x = event->pos().x() - 25;
        int y = event->pos().y() - 25;
        circles.get(circles.getSize() - 1)->move(x, y);
        repaint();
    }
}
