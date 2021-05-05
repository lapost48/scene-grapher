#ifndef EDGE_H
#define EDGE_H

#include "circlenode.h"

#include <QDebug>

enum EndNode { FIRST, SECOND };

class Edge
{

public:
    Edge(CircleNode* a, CircleNode* b);
    ~Edge();
    CircleNode& get(EndNode index);
    void setNode(EndNode index, CircleNode* newNode);
    bool contains(CircleNode node);

private:
    CircleNode* nodes[2];
};

#endif // EDGE_H
