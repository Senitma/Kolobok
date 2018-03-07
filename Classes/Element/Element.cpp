#include "Element.h"

Element::Element(cocos2d::Node * node, ElementNameType name, ClassType type)
{
	this->node = node;
	this->name = name;
	this->type = type;

	currentPoint = BaseAxes(0, 0);
}

void Element::AddPoint(int x, int y)
{
	this->points.push_back(BaseAxes(x, y));
}


