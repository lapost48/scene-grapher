#include "statemachine.h"

State::State(CircleGraph* g)
{
    graph = g;
}

State::~State()
{

}

DefaultState::DefaultState(CircleGraph* g)
    : State(g)
{

}

DefaultState::~DefaultState()
{

}

State* DefaultState::updateState(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(graph->numCircles() > 0)
        {
            bool insideOldNode = graph->circleLocator.isInsideNode(event->pos());
            CircleNode& node = graph->circleLocator.nearestCircle((event->pos()));

            int x = event->pos().x() - 25;
            int y = event->pos().y() - 25;
            graph->addCircle(CircleNode(x, y, 50));

            if(insideOldNode)
                graph->addEdge(Edge(&node, &graph->getCircle(graph->numCircles() - 1)));
            return new MovingNodeState(graph, &graph->getCircle(graph->numCircles() - 1));
        }
        else
        {
            int x = event->pos().x() - 25;
            int y = event->pos().y() - 25;
            graph->addCircle(CircleNode(x, y, 50));
            return new MovingNodeState(graph, &graph->getCircle(graph->numCircles() - 1));
        }
    }
    else if(event->button() == Qt::RightButton)
    {
        CircleNode& node = graph->circleLocator.nearestCircle((event->pos()));
        node.setColor(Qt::GlobalColor::red);
        return this;
    }
    else
    {
        return this;
    }
}

MovingNodeState::MovingNodeState(CircleGraph* g, CircleNode* a)
    : State(g)
{
    activeNode = a;
}

MovingNodeState::~MovingNodeState()
{

}

State* MovingNodeState::updateState(QMouseEvent* event)
{
    if(event->button() == Qt::NoButton)
    {
        int x = event->pos().x() - 25;
        int y = event->pos().y() - 25;
        activeNode->move(x, y);
        return this;
    }
    else if(event->button() == Qt::LeftButton || event->button() == Qt::RightButton)
    {
        return new DefaultState(graph);
    }
    else
    {
        return this;
    }
}

StateMachine::StateMachine(CircleGraph* g)
{
    currentState = new DefaultState(g);

}

StateMachine::~StateMachine()
{
    delete currentState;
}

bool StateMachine::transition(QMouseEvent* event)
{
    State* temp = currentState->updateState(event);
    if(temp != currentState)
    {
        delete currentState;
        currentState = temp;
        return true;
    }
    return false;
}

