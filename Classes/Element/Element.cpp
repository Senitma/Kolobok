#include "Element.h"

Element::Element(cocos2d::Node * node, const ElementNameType & name, const ClassType & type)
{
	this->node = node;
	this->name = name;
	this->type = type;

	points = std::vector<BaseAxes>{ BaseAxes(0, 0) };
}

void Element::AddPoint(const int & x, const int & y)
{
	this->points.push_back(BaseAxes(x, y));
}


