#include "AdvancedElement.h"

void AdvancedElement::SetXY(FieldPoint value)
{
}
void AdvancedElement::SetSide(SideType value)
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
}
