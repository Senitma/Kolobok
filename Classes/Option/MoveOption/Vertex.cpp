#include "Vertex.h"

// Инициализация статической переменной
int BaseVertex::maxX = 0;

Vertex::Vertex(const int & x, const int & y, const int & counter) : BaseVertex(x, y, counter)
{
	sideCounter = Vertex::EMPTYINDEX;
	weight = 0;

	mainPrevEdge = Edge();
	addPrevEdge = Edge();

	leftEdge = Edge();
	upEdge = Edge();
	rightEdge = Edge();
	downEdge = Edge();
}
