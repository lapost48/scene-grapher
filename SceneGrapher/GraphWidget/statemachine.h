#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "CircleGraph/circlegraph.h"

#include <QMouseEvent>

class State
{

public:
    State(CircleGraph* g);
    virtual ~State();
    virtual State* updateState(QMouseEvent*){return nullptr;}

protected:
    CircleGraph* graph;
};

class DefaultState
        : public State
{

public:
    DefaultState(CircleGraph* g);
    ~DefaultState();
    State* updateState(QMouseEvent* event);
};

class MovingNodeState
        : public State
{

public:
    MovingNodeState(CircleGraph* g, CircleNode* a);
    ~MovingNodeState();
    State* updateState(QMouseEvent* event);

private:
    CircleNode* activeNode;
};

class StateMachine
{

public:
    StateMachine(CircleGraph* g);
    ~StateMachine();
    bool transition(QMouseEvent *event);

private:
    State* currentState;
};

#endif // STATEMACHINE_H
