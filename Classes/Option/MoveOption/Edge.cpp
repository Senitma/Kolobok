#include "Vertex.h"
#include "Edge.h"

int Edge::GetX() const
{
	return vertex->GetX();
}
int Edge::GetY() const
{
	return vertex->GetY();
}
int Edge::GetIndex() const
{
	return vertex->GetIndex();
}
int Edge::GetCounter() const
{
	return vertex->GetCounter();
}
void Edge::SetCounter(const int & value)
{
	vertex->SetCounter(value);
}

int Edge::GetSideCounter() const
{
	return vertex->GetSideCounter();
}
void Edge::SetSideCounter(const int & value)
{
	vertex->SetSideCounter(value);
}
int Edge::GetWeight() const
{
	return vertex->GetWeight();
}
void Edge::SetWeight(const int & value)
{
	vertex->SetWeight(value);
}
SideType Edge::GetSide()
{
	return vertex->GetSide();
}
void Edge::SetSide(const SideType & value)
{
	vertex->SetSide(value);
}

Edge & Edge::GetMainPrevEdge()
{
	return vertex->GetMainPrevEdge();
}
Edge & Edge::GetAddPrevEdge()
{
	return vertex->GetAddPrevEdge();
}

Edge & Edge::GetLeftEdge()
{
	return vertex->GetLeftEdge();
}
Edge & Edge::GetUpEdge()
{
	return vertex->GetUpEdge();
}
Edge & Edge::GetRightEdge()
{
	return vertex->GetRightEdge();
}
Edge & Edge::GetDownEdge()
{
	return vertex->GetDownEdge();
}
