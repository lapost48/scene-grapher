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
    if(event->button() == Qt::LeftButton)
    {
        switch(mode)
        {
        case CREATE:
            return CreatingNodeState(graph).updateState(event, mode);
            break;
        case MOVE:
            if(graph->numCircles() > 0)
            {
                if(graph->circleLocator.isInsideNode(event->pos()))
                {
                   return new MovingNodeState(graph, &graph->circleLocator.nearestCircle(event->pos()));
                }
            }
            break;
        case DELETE:
            if(graph->numCircles() > 0)
            {
                return DeletingNodeState(graph).updateState(event, mode);
            }
            break;
        case DEFAULT:
            break;
        }
    }
    return this;
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
    activeNode->setColor(Qt::GlobalColor::darkGray);
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
                CircleNode& lastNode = graph->getCircle(graph->numCircles() - 1);
                lastNode.setColor(Qt::GlobalColor::black);
                if(graph->numEdges() > 0)
                {
                    if(graph->getEdge(graph->numEdges() - 1).contains(edgeNode))
                    {
                        graph->getEdge(graph->numEdges() - 1).setNode(EndNode::SECOND, &lastNode);
                    }
                }
            }
        }
        activeNode->setColor(Qt::GlobalColor::black);
        return new DefaultState(graph);
    }
    else
    {
        activeNode->setColor(Qt::GlobalColor::black);
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

