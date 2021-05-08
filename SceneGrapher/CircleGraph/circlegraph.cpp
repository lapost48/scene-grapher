#include "circlegraph.h"

#include <QDebug>

CircleGraph::CircleGraph()
    : circleLocator(&nodes)
{

}

CircleGraph::~CircleGraph()
{
    for(CircleNode* node : nodes)
    {
       delete node;
    }

    nodes.clear();
}

int CircleGraph::numCircles()
{
    return nodes.size();
}

int CircleGraph::addCircle(CircleNode newNode)
{
    CircleNode * val = new CircleNode(newNode);
    nodes.push_back(val);
    return nodes.size();
}

CircleNode CircleGraph::popCircle()
{
    CircleNode ret =  *nodes.back();
    nodes.pop_back();
    return ret;
}

void CircleGraph::removeCircle(int index)
{
    std::list<CircleNode*>::iterator it = nodes.begin();
    advance(it,index);
    nodes.erase(it);
}

void CircleGraph::removeCircle(CircleNode* nodePtr)
{
    nodes.remove(nodePtr);
}

CircleNode& CircleGraph::getCircle(int index)
{
    std::list<CircleNode*>::iterator it = nodes.begin();
    advance(it,index);
    return **it;
}

std::list<CircleNode*>::iterator CircleGraph::circleIterator()
{
    return nodes.begin();
}

int CircleGraph::numEdges()
{
    return edges.size();
}

int CircleGraph::addEdge(Edge newEdge)
{
    edges.push_back(newEdge);
    return edges.size();
}

Edge& CircleGraph::getEdge(int index)
{
    std::list<Edge>::iterator it = edges.begin();
    advance(it,index);
    return *it;
}

Edge& CircleGraph::popEdge()
{
    Edge& ret =  edges.back();
    edges.pop_back();
    return ret;
}
