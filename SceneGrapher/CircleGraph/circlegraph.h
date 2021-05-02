#ifndef CIRCLEGRAPH_H
#define CIRCLEGRAPH_H

#include "edge.h"
#include "circlenode.h"
#include "circlelocator.h"

#include <QPoint>

#include <list>

class CircleGraph
{
public:
    CircleLocator circleLocator;
//    EdgeLocator edgeLocator;

    CircleGraph();
    ~CircleGraph();
    int numCircles();
    int addCircle(CircleNode newNode);
    CircleNode& popCircle();
    void removeCircle(int index);
    CircleNode& getCircle(int index);
    std::list<CircleNode*>::iterator circleIterator();
//    CircleNode& find(CircleNode* nodeRef);
    int numEdges();
    int addEdge(Edge newEdge);
    Edge& getEdge(int index);
    Edge& popEdge();

private:
    std::list<CircleNode*> nodes;
    std::list<Edge> edges;

};

#endif // CIRCLEGRAPH_H
