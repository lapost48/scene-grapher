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
            {
                graph->addEdge(Edge(&node, &graph->getCircle(graph->numCircles() - 1)));
            }
            return new MovingNodeState(graph, &graph->getCircle(graph->numCircles() - 1), Qt::LeftButton);
        }
        else
        {
            int x = event->pos().x() - 25;
            int y = event->pos().y() - 25;
            graph->addCircle(CircleNode(x, y, 50));
            return new MovingNodeState(graph, &graph->getCircle(graph->numCircles() - 1), Qt::LeftButton);
        }
    }
    else if(event->button() == Qt::RightButton)
    {
        if(graph->circleLocator.isInsideNode(event->pos()))
        {
            return new MovingNodeState(graph, &graph->circleLocator.nearestCircle((event->pos())), Qt::RightButton);
        }
        return this;
    }
    else
    {
        return this;
    }
}

MovingNodeState::MovingNodeState(CircleGraph* g, CircleNode* a, Qt::MouseButton action)
    : State(g)
{
    activeNode = a;
    enterAction = action;
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
    else if(event->button() == enterAction)
    {
        if(enterAction == Qt::LeftButton)
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

