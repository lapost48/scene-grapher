#include "circlegraph.h"

//namespace CircleGraph {

CircleNode::CircleNode(int x, int y, int s)
{
    xPos = x;
    yPos = y;
    size = s;
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


CircleGraph::CircleGraph()
{

}

CircleGraph::~CircleGraph()
{
    for(CircleNode* ptr : nodes)
    {
        delete ptr;
    }
    nodes.clear();
}

int CircleGraph::getSize()
{
    return nodes.size();
}

int CircleGraph::add(CircleNode* newNode)
{
    nodes.push_back(newNode);
    return nodes.size();
}

void CircleGraph::remove(int index)
{
    std::list<CircleNode*>::iterator it = nodes.begin();
    advance(it,index);
    delete *it;
    nodes.erase(it);
}

CircleNode* CircleGraph::get(int index)
{
    std::list<CircleNode*>::iterator it = nodes.begin();
    advance(it,index);
    return *it;
}

//}
