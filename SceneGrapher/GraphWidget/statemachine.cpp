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

State* DefaultState::updateState(QMouseEvent *event, GraphMode mode)
{
    if(mode == CREATE)
    {
        return CreatingNodeState(graph).updateState(event, mode);
    }
    else if(mode == MOVE)
    {
        if(graph->numCircles() > 0)
        {
            return new MovingNodeState(graph, &graph->circleLocator.nearestCircle(event->pos()));
        }
        else
        {
            return this;
        }
    }
    else if(mode == DELETE)
    {
        if(graph->numCircles() > 0)
        {
            return DeletingNodeState(graph).updateState(event, mode);
        }
        else
        {
            return this;
        }
    }
    else
    {
        return this;
    }
}

CreatingNodeState::CreatingNodeState(CircleGraph* g)
    : State(g)
{

}

CreatingNodeState::~CreatingNodeState()
{

}

State* CreatingNodeState::updateState(QMouseEvent* event, GraphMode)
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
            {
                graph->addEdge(Edge(&node, &graph->getCircle(graph->numCircles() - 1)));
            }
        }
        else
        {
            int x = event->pos().x() - 25;
            int y = event->pos().y() - 25;
            graph->addCircle(CircleNode(x, y, 50));
        }
        return new MovingNodeState(graph, &graph->getCircle(graph->numCircles() - 1));
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

State* MovingNodeState::updateState(QMouseEvent* event, GraphMode mode)
{
    if(event->button() == Qt::NoButton)
    {
        int x = event->pos().x() - 25;
        int y = event->pos().y() - 25;
        activeNode->move(x, y);
        return this;
    }
    else if(event->button() == Qt::LeftButton)
    {
        if(mode == CREATE)
        {
            CircleNode edgeNode = graph->popCircle();
            if(graph->circleLocator.isInsideNode(event->pos()))
            {
                if(graph->numEdges() > 0)
                {
                    if(graph->getEdge(graph->numEdges() - 1).contains(edgeNode))
                    {
                        CircleNode* oldNode = &graph->circleLocator.nearestCircle(event->pos());
                        graph->getEdge(graph->numEdges() - 1).setNode(EndNode::SECOND, oldNode);
                    }
                }
            }
            else
            {
                graph->addCircle(edgeNode);
                if(graph->numEdges() > 0)
                {
                    if(graph->getEdge(graph->numEdges() - 1).contains(edgeNode))
                    {
                        CircleNode& lastNode = graph->getCircle(graph->numCircles() - 1);
                        graph->getEdge(graph->numEdges() - 1).setNode(EndNode::SECOND, &lastNode);
                    }
                }
            }

        }
        return new DefaultState(graph);
    }
    else
    {
        return this;
    }
}

DeletingNodeState::DeletingNodeState(CircleGraph* g)
    : State(g)
{

}

DeletingNodeState::~DeletingNodeState()
{

}

State* DeletingNodeState::updateState(QMouseEvent* event, GraphMode)
{
    if(graph->circleLocator.isInsideNode(event->pos()))
    {
        CircleNode* node = &graph->circleLocator.nearestCircle(event->pos());
        graph->removeCircle(node);
    }
    return new DefaultState(graph);
}

StateMachine::StateMachine(CircleGraph* g)
{
    currentState = new DefaultState(g);
    mode = DEFAULT;
}

StateMachine::~StateMachine()
{
    delete currentState;
}

bool StateMachine::transition(QMouseEvent* event)
{
    State* temp = currentState->updateState(event, mode);
    if(temp != currentState)
    {
        delete currentState;
        currentState = temp;
        return true;
    }
    return false;
}

bool StateMachine::setMode(GraphMode actionType)
{
    mode = actionType;
}

