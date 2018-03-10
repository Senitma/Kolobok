#include "AdvancedElement.h"
#include "Field\Field.h"

AdvancedElement::AdvancedElement(cocos2d::Node * node, ElementNameType name, ClassType type)
{
	this->node = node;
	this->name = name;
	this->type = type;

	points = std::vector<BaseAxes>{ BaseAxes(0, 0) };

	isDestroy = false;
}

void AdvancedElement::SetAxes(const int & x, const int & y)
{
	if (Field::ContainElement(this) == true)
	{
		Field::RemoveElement(*this);
		SetX(x);
		SetY(y);
		Field::AddElement(*this);
	}
}
void AdvancedElement::SetSide(const SideType & value)
{
	this->side = value;

	switch (side)
	{
	case SideType::Left:
		node->setRotation(90);
		break;
	case SideType::Right:
		node->setRotation(270);
		break;
	case SideType::Up:
		node->setRotation(180);
		break;
	case SideType::Down:
		node->setRotation(0);
		break;
	}
}

int AdvancedElement::GetLeft()
{
	if (isDestroy == false)
	{
		return node->getPosition().x;
	}

	return 0;
}
int AdvancedElement::GetTop()
{
	if (isDestroy == false)
	{
		return node->getPosition().y;
	}

	return 0;
}
void AdvancedElement::SetPosition(cocos2d::Vec2 value)
{
	if (isDestroy == false)
	{
		node->setPosition(value);
	}
}
int AdvancedElement::GetRotation()
{
	if (isDestroy == false)
	{
		return node->getRotation();
	}

	return 0;
}
void AdvancedElement::SetRotation(int value)
{
	if (isDestroy == false)
	{
		node->setRotation(value);
	}
}

void AdvancedElement::Destroy()
{
	if (isDestroy == false)
	{
		Field::RemoveElement(*this);

		for (int index = 0; index < items.size(); index++)
		{
			items.at(index)->Destroy();
			delete items.at(index);
		}

		node->getParent()->removeChild(node);
	}
}
