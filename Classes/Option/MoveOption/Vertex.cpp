#include "Vertex.h"

Vertex::Vertex(const int & x, const int & y, const int & counter) : Axes(x, y)
{
	sideCounter = Vertex::EMPTYINDEX;
	offsetCounter = 0;
	weight = 0;

	mainPrevEdge = Edge();
	addPrevEdge = Edge();
	progenitor = Edge();

	leftNearEdge = Edge();
	upNearEdge = Edge();
	rightNearEdge = Edge();
	downNearEdge = Edge();

	leftFarEdge = Edge();
	upFarEdge = Edge();
	rightFarEdge = Edge();
	downFarEdge = Edge();

	this->counter = counter;
}
