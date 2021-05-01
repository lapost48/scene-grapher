#include "circlegraph.h"

//namespace CircleGraph {

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

CircleLocator::CircleLocator(std::list<CircleNode>* circles)
{
    nodes = circles;
}

CircleLocator::~CircleLocator()
{

}

CircleNode& CircleLocator::nearestCircle(QPoint point)
{
    std::list<CircleNode>::iterator it = nodes->begin();

    CircleNode* nearestNode = &*it;
//    CircleNode* nea = &nearestNode;
    int itX = it->getX() + (it->getSize() / 2);
    int itY = it->getY() + (it->getSize() / 2);
    double minDist = sqrt(pow(itX - point.x(),2) + pow(itY - point.y(), 2)) - it->getSize();

    do
    {
        itX = it->getX() + (it->getSize() / 2);
        itY = it->getY() + (it->getSize() / 2);
        double dist = sqrt(pow(itX - point.x(),2) + pow(itY - point.y(), 2)) - it->getSize();
        if(dist < minDist)
        {
            nearestNode = &*it;
            minDist = dist;
        }
        std::advance(it, 1);
    } while(it != nodes->end());

    return *nearestNode;
}

CircleGraph::CircleGraph()
    : circleLocator(&nodes)
{

}

CircleGraph::~CircleGraph()
{

}

int CircleGraph::getSize()
{
    return nodes.size();
}

int CircleGraph::add(CircleNode newNode)
{
    nodes.push_back(newNode);
    return nodes.size();
}

void CircleGraph::remove(int index)
{
    std::list<CircleNode>::iterator it = nodes.begin();
    advance(it,index);
    nodes.erase(it);
}

CircleNode& CircleGraph::get(int index)
{
    std::list<CircleNode>::iterator it = nodes.begin();
    advance(it,index);
    return *it;
}

std::list<CircleNode>::iterator CircleGraph::circleIterator()
{
    return nodes.begin();
}

//}
