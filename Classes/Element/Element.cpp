#include "Element.h"
#include "ElementData.h"
#include "Field\Field.h"

Element::Element(cocos2d::Node * node, ElementNameType name, ClassType type)
{
	data->node = node;
}

void Element::SetSide(const SideType & value)
{
	this->data->side = value;

	switch (value)
	{
	case SideType::Left:
		data->node->setRotation(90);
		break;
	case SideType::Right:
		data->node->setRotation(270);
		break;
	case SideType::Up:
		data->node->setRotation(180);
		break;
	case SideType::Down:
		data->node->setRotation(0);
		break;
	}
}
void Element::SetX(const int & value)
{
	data->position.SetX(value);
}
void Element::SetY(const int & value)
{
	data->position.SetY(value);
}
void Element::SetAxes(const int & x, const int & y)
{
	// Доделать!
	//if (Field::ContainElement(this) == true)
	{
		//Field::RemoveElement(*this);
		data->position.SetX(x);
		data->position.SetY(y);
		//Field::AddElement(*this);
	}
}

int Element::GetLeft() const
{
	if (data->GetDestroyStatus() == false)
	{
		return data->node->getPosition().x;
	}

	return 0;
}
int Element::GetTop() const
{
	if (data->GetDestroyStatus() == false)
	{
		return data->node->getPosition().y;
	}

	return 0;
}
int Element::GetRotation() const
{
	if (data->GetDestroyStatus() == false)
	{
		return data->node->getRotation();
	}

	return 0;
}
void Element::SetPosition(const int & x, const int & y)
{
	if (data->GetDestroyStatus() == false)
	{
		data->node->setPosition(cocos2d::Vec2(x,y));
	}
}
void Element::SetRotation(const int & value)
{
	if (data->GetDestroyStatus() == false)
	{
		data ->node->setRotation(value);
	}
}

void Element::AddPoint(const int & x, const int & y)
{
	data->patrolPoints.push_back(BaseAxes(x, y));
}
BaseAxes Element::GetPoint(const int & index)
{
	return data->patrolPoints.at(index);
}
int Element::GetPointLength() const
{
	return data->patrolPoints.size();
}

void Element::AddOption(ISInterval * option)
{
	data->options.push_back(option);
}

bool Element::operator==(const Element & value)
{
	return data->node == value.data->node;
}

bool Element::operator!=(const Element & value)
{
	return data->node != value.data->node;
}
