#include "edge.h"

Edge::Edge(CircleNode* a, CircleNode* b)
{
    nodes[FIRST] = a;
    nodes[SECOND] = b;
}

Edge::~Edge()
{

}

CircleNode& Edge::get(EndNode index)
{
    return *nodes[index];
}

void Edge::setNode(EndNode index, CircleNode *newNode)
{
    nodes[index] = newNode;
}

bool Edge::contains(CircleNode node)
{
    return (*nodes[FIRST] == node || *nodes[SECOND] == node);
}
