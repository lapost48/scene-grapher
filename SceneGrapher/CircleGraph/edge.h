#ifndef EDGE_H
#define EDGE_H

#include "circlenode.h"

enum EndNode { FIRST, SECOND };

class Edge
{

public:
    Edge(CircleNode* a, CircleNode* b);
    ~Edge();
    CircleNode& get(EndNode index);

private:
    CircleNode* first;
    CircleNode* second;
};

#endif // EDGE_H
