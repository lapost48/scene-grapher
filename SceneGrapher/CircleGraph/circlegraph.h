#ifndef CIRCLEGRAPH_H
#define CIRCLEGRAPH_H

#include <QPoint>
//#include <qDebug>

#include <list>
#include <cmath>

class CircleNode
{

public:
    CircleNode(int x, int y, int size);
    ~CircleNode();
    int getSize();
    int getY();
    int getX();
    void move(int x, int y);
    void setColor(Qt::GlobalColor color);
    Qt::GlobalColor getColor();

private:
    int xPos;
    int yPos;
    int size;
    Qt::GlobalColor circleColor;

};

class CircleLocator
{

public:
    CircleLocator(std::list<CircleNode>*);
    ~CircleLocator();
    CircleNode& nearestCircle(QPoint point);

private:
    std::list<CircleNode>* nodes;
};

class CircleGraph
{
public:
    CircleLocator circleLocator;
//    EdgeLocator edgeLocator;

    CircleGraph();
    ~CircleGraph();
    int getSize();
    int add(CircleNode newNode);
    void remove(int index);
    CircleNode& get(int index);
    std::list<CircleNode>::iterator circleIterator();
//    CircleNode& find(CircleNode* nodeRef);

private:
    std::list<CircleNode> nodes;

//    std::list<Edges> edges;

};

#endif // CIRCLEGRAPH_H
