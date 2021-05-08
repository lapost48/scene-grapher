#include "graphwidget.h"
#include "statemachine.h"

#include <QtDebug>


GraphWidget::GraphWidget()
    : QWidget(), stateMachine(&graph)
{

}

GraphWidget::~GraphWidget()
{

}

void GraphWidget::toDefaultMode(bool)
{
    stateMachine.setMode(DEFAULT);
}

void GraphWidget::toCreateMode(bool)
{
    qDebug() << "Create Mode";
    stateMachine.setMode(CREATE);
}
void GraphWidget::toMoveMode(bool)
{
    stateMachine.setMode(MOVE);
}

void GraphWidget::toDeleteMode(bool)
{
    qDebug() << "Delete Mode";
    stateMachine.setMode(DELETE);
}

void GraphWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    for(int i = 0; i < graph.numEdges(); i++)
    {
        Edge edge = graph.getEdge(i);
        CircleNode temp = edge.get(EndNode::FIRST);
        int x1 = temp.getX() + (temp.getSize() / 2);
        int y1 = temp.getY() + (temp.getSize() / 2);
        temp = edge.get(EndNode::SECOND);
        int x2 = temp.getX() + (temp.getSize() / 2);
        int y2 = temp.getY() + (temp.getSize() / 2);
        p.drawLine(x1, y1, x2, y2);
    }
    for(int i = 0; i < graph.numCircles(); i++)
    {
        CircleNode node = graph.getCircle(i);
        p.setBrush(QBrush(node.getColor()));
        p.drawEllipse(node.getX(), node.getY(), node.getSize(), node.getSize());
    }
}

void GraphWidget::mousePressEvent(QMouseEvent *event)
{
    stateMachine.transition(event);
    repaint();
}

void GraphWidget::mouseReleaseEvent(QMouseEvent *event)
{
    stateMachine.transition(event);
    repaint();
}

void GraphWidget::mouseMoveEvent(QMouseEvent *event)
{
    stateMachine.transition(event);
    repaint();
}
