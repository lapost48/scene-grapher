#ifndef LOCATOR_H
#define LOCATOR_H

#include "CircleGraph/circlegraph.h"

class Locator
{

public:
    Locator(CircleGraph*);
    ~Locator();

private:
    CircleGraph* graph;
};

#endif // LOCATOR_H
