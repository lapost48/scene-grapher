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

//        for(int i = 0; i < circles.getSize(); i++)
//        {
//            qDebug() << circles.get(i).getX() << ":" << circles.get(i).getY();
//        }
        int x = event->pos().x() - 25;
        int y = event->pos().y() - 25;
        circles.get(circles.getSize() - 1)->move(x, y);
        qDebug() << circles.get(circles.getSize() - 1)->getX() << ":" << circles.get(circles.getSize() - 1)->getY();
        repaint();
    }
}
