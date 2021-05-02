#include "edge.h"

Edge::Edge(CircleNode* a, CircleNode* b)
{
    first = a;
    second = b;
}

Edge::~Edge()
{

}

CircleNode& Edge::get(EndNode index)
{
    if(index == 0)
        return *first;
    else
        return *second;
}
