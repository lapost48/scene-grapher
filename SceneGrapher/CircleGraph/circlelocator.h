#ifndef CIRCLELOCATOR_H
#define CIRCLELOCATOR_H

#include "circlenode.h"

#include <list>
#include <cmath>

class CircleLocator
{

public:
    CircleLocator(std::list<CircleNode>*);
    ~CircleLocator();
    CircleNode& nearestCircle(QPoint point);
    bool isInsideNode(QPoint point);

private:
    std::list<CircleNode>* nodes;
};

#endif // CIRCLELOCATOR_H
