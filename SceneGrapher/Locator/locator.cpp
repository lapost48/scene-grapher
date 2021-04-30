#include "locator.h"

Locator::Locator(CircleGraph* g)
{
    graph = g;
}

Locator::~Locator()
{
    delete graph;
}

