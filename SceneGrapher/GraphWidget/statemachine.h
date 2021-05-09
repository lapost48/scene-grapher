#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "graphmode.h"
#include "CircleGraph/circlegraph.h"

#include <QMouseEvent>

class State
{

public:
    State(CircleGraph* g);
    virtual ~State();
    virtual State* updateState(QMouseEvent*, GraphMode mode){return nullptr;}

protected:
    CircleGraph* graph;
};

class DefaultState
        : public State
{

public:
    DefaultState(CircleGraph* g);
    ~DefaultState();
    State* updateState(QMouseEvent* event, GraphMode);
};

class CreatingNodeState
        : public State
{

public:
    CreatingNodeState(CircleGraph* g);
    ~CreatingNodeState();
    State* updateState(QMouseEvent* event, GraphMode);
};

class MovingNodeState
        : public State
{

public:
    MovingNodeState(CircleGraph* g, CircleNode* a);
    ~MovingNodeState();
    State* updateState(QMouseEvent* event, GraphMode mode);

private:
    CircleNode* activeNode;
};

class DeletingNodeState
        : public State
{

public:
    DeletingNodeState(CircleGraph* g);
    ~DeletingNodeState();
    State* updateState(QMouseEvent* event, GraphMode);
};

class StateMachine
{

public:
    StateMachine(CircleGraph* g);
    ~StateMachine();
    bool transition(QMouseEvent *event);
    bool setMode(GraphMode actionMode);

private:
    State* currentState;
    GraphMode mode;
};

#endif // STATEMACHINE_H
