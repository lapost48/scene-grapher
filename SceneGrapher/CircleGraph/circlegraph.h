#ifndef CIRCLEGRAPH_H
#define CIRCLEGRAPH_H

#include <list>

class CircleNode
{
public:
    CircleNode(int x, int y, int size);
    ~CircleNode();
    int getSize();
    int getY();
    int getX();
    void move(int x, int y);

private:
    int xPos;
    int yPos;
    int size;
};

class CircleGraph
{
public:
    CircleGraph();
    ~CircleGraph();
    int getSize();
    int add(CircleNode* newNode);
    void remove(int index);
    CircleNode* get(int index);
    CircleNode* find(CircleNode* nodeRef);

private:
    std::list<CircleNode*> nodes;
//    std::vector<Edges> edges;

};

#endif // CIRCLEGRAPH_H
