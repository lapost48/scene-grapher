#include "circlelocator.h"

#include <QDebug>

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

bool CircleLocator::isInsideNode(QPoint point)
{
    if(nodes->size() < 1)
        return false;

    std::list<CircleNode>::iterator it = nodes->begin();

    do
    {
        int itX = it->getX() + (it->getSize() / 2);
        int itY = it->getY() + (it->getSize() / 2);
        double dist = sqrt(pow(itX - point.x(),2) + pow(itY - point.y(), 2)) - it->getSize();
//        qDebug() << "X:" << itX << "Y:" << itY;
//        qDebug() << "X:" << point.x() << "Y:" << point.y() << "D:" << dist;
        if(dist < 0)
        {
            return true;
        }
        std::advance(it, 1);
    } while(it != nodes->end());
    return false;
}
