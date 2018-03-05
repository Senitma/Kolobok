#include "Element.h"

Element::Element(cocos2d::Node * node, ElementNameType name, ClassType type)
{
	this->node = node;
	this->name = name;
	this->type = type;

	currentPoint = new FieldPoint(0, 0);
}

void Element::AddPoint(FieldPoint * point)
{
	this->points.pushBack(point);
}
void Element::RemovePoint(FieldPoint * point)
{
	if (points.contains(point) == true)
	{
		points.eraseObject(point, true);
	}
	else
	{
		for (int index = 0; index < this->points.size(); index++)
		{
			FieldPoint * item = this->points.at(index);
			if (item->GetX() == point->GetX() && item->GetY() == point->GetY())
			{
				points.eraseObject(item, true);
			}
		}
	}
}

void Element::Destroy()
{
}


