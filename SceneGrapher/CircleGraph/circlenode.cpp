#include "circlenode.h"

CircleNode::CircleNode(int x, int y, int s)
{
    xPos = x;
    yPos = y;
    size = s;
    circleColor = Qt::GlobalColor::black;
}

CircleNode::CircleNode(const CircleNode& val)
{
    xPos = val.xPos;
    yPos = val.yPos;
    size = val.size;
    circleColor = val.circleColor;
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

bool CircleNode::operator==(CircleNode otherNode)
{
    bool equal = xPos == otherNode.getX();
    equal &= yPos == otherNode.getY();
    equal &= size == otherNode.getSize();
    equal &= circleColor == otherNode.getColor();
    return equal;
}
