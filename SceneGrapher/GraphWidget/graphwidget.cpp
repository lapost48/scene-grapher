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
    for(int i = 0; i < circles.numCircles(); i++)
    {
        CircleNode node = circles.getCircle(i);
        p.setBrush(QBrush(node.getColor()));
        p.drawEllipse(node.getX(), node.getY(), node.getSize(), node.getSize());
    }
    for(int i = 0; i < circles.numEdges(); i++)
    {
        Edge edge = circles.getEdge(i);
        CircleNode temp = edge.get(EndNode::FIRST);
        int x1 = temp.getX() + (temp.getSize() / 2);
        int y1 = temp.getY() + (temp.getSize() / 2);
        temp = edge.get(EndNode::SECOND);
        int x2 = temp.getX() + (temp.getSize() / 2);
        int y2 = temp.getY() + (temp.getSize() / 2);
//        p.setBrush(QBrush(edge.getColor()));
        p.drawLine(x1, y1, x2, y2);
    }
}

void GraphWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        bool insideOldNode = circles.circleLocator.isInsideNode(event->pos());
        CircleNode& node = circles.circleLocator.nearestCircle((event->pos()));

        int x = event->pos().x() - 25;
        int y = event->pos().y() - 25;
        circles.addCircle(CircleNode(x, y, 50));
        leftPressed = true;

        if(insideOldNode)
            circles.addEdge(Edge(&node, &circles.getCircle(circles.numCircles() - 1)));
    }
    if(event->button() == Qt::RightButton)
    {
        CircleNode& node = circles.circleLocator.nearestCircle((event->pos()));
        node.setColor(Qt::GlobalColor::red);
    }
    repaint();
}

void GraphWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        CircleNode& tempCircle = circles.popCircle();
        if(!circles.circleLocator.isInsideNode(event->pos()))
        {
            circles.addCircle(tempCircle);
        }
        else
        {
            Edge& tempEdge = circles.getEdge(circles.numEdges() - 1);
            CircleNode& newNode = tempEdge.get(EndNode::SECOND);
            newNode = circles.circleLocator.nearestCircle(event->pos());
        }
        leftPressed = false;
    }
    if(event->button() == Qt::RightButton)
    {
        CircleNode& node = circles.circleLocator.nearestCircle((event->pos()));
        node.setColor(Qt::GlobalColor::black);
    }
    repaint();
}

void GraphWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(leftPressed)
    {
        int x = event->pos().x() - 25;
        int y = event->pos().y() - 25;
        circles.getCircle(circles.numCircles() - 1).move(x, y);
    }
    repaint();
}
