#include "circlenode.h"

CircleNode::CircleNode(int x, int y, int s)
{
    xPos = x;
    yPos = y;
    size = s;
    circleColor = Qt::GlobalColor::black;
}

CircleNode::~CircleNode()
{

}

int CircleNode::getSize()
{
    return size;
}

int CircleNode::getX()
{
    return xPos;
}

int CircleNode::getY()
{
    return yPos;
}

void CircleNode::move(int x, int y)
{
    xPos = x;
    yPos = y;
}

void CircleNode::setColor(Qt::GlobalColor color)
{
    circleColor = color;
}

Qt::GlobalColor CircleNode::getColor()
{
    return circleColor;
}
