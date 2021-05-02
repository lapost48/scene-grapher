#ifndef CIRCLENODE_H
#define CIRCLENODE_H

#include <QPoint>

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

#endif // CIRCLENODE_H
