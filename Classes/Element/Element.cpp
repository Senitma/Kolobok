#include "AnimationType.h"
#include "ElementData.h"
#include "Field\AxesInfo.h"
#include "Settings.h"

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"

#include "Element.h"

// Статус автоматического удаления прорисовок
bool AutoDrawDeleteStatus = true;

Element::Element(cocos2d::Node * node, SideType side, ElementNameType name, ClassType type)
{
	static int id = 0;
	data = std::make_shared<ElementData>();

	data->id = id;
	data->node = node;
	data->side = side;
	data->name = name;
	data->type = type;

	if (side != SideType::None)
	{
		data->animation.LoadAnimation(data->node, Settings::ROTATESPEED, 5, Settings::NODEWIDTH, Settings::NODEHEIGHT, side);
	}

	id++;
}
Element::Element(const Element & value)
{
	data = std::move(value.data);
}
Element::~Element()
{
	if ((data.use_count() == 1) && (AutoDrawDeleteStatus == true))
	{
		data->node->removeFromParent();
	}
}
void Element::OffAutoDrawDelete()
{
	AutoDrawDeleteStatus = false;
}

ElementNameType Element::GetName() const
{
	return data->name;
}
ClassType Element::GetType() const
{
	return data->type;
}
SideType Element::GetSide() const
{
	return data->side;
}
void Element::SetSide(const SideType & value)
{
	data->side = value;
}

int Element::GetX() const
{
	return data->position.GetX();
}
int Element::GetY() const
{
	return data->position.GetY();
}
Axes Element::GetAxes() const
{
	return data->position;
}

int Element::GetLeft() const
{
	return data->node->getPosition().x;
}
int Element::GetTop() const
{
	return data->node->getPosition().y;
}
void Element::SetPosition(const int & x, const int & y)
{
	data->node->setPosition(cocos2d::Vec2(x, y));
}
int Element::GetRotation() const
{
	return data->node->getRotation();
}
void Element::SetRotation(const int & value)
{
	data->node->setRotation(value);
}
bool Element::GetDestroyStatus() const
{
	return data->destroyStatus;
}
void Element::SetDestroyStatus(const bool & value)
{
	data->destroyStatus = value;
}

void Element::RunAnimation(AnimationType type)
{
	switch (type)
	{
		case AnimationType::MoveToLeft:
			// Анимация движения
		case AnimationType::MoveToUp:
			// Анимация движения
		case AnimationType::MoveToRight:
			// Анимация движения
		case AnimationType::MoveToDown:
		{
			auto move = cocos2d::MoveTo::create(0.3F, cocos2d::Vec2(AxesInfo::ConvertToLeft(data->position.GetX()), AxesInfo::ConvertToTop(data->position.GetY())));
			data->node->runAction(move);

			break;
		}
		default:
			data->animation.RunAnimation(type);
			break;
	}
}

void Element::AddPoint(const int & x, const int & y)
{
	// Для повторной проверки маршрута координаты дублируются
	data->patrolPoints.push(Axes(x, y));
	data->patrolPoints.push(Axes(x, y));
}
std::queue<Axes> & Element::GetPoints()
{
	return data->patrolPoints;
}

Element Element::operator=(const Element & value) const
{
	return Element(value);
}
bool Element::operator==(const Element & value) const
{
	return data->id == value.data->id;
}
bool Element::operator!=(const Element & value) const
{
	return data->id != value.data->id;
}

int Element::GetID() const
{
	return data->id;
}
void Element::SetX(const int & value)
{
	data->position.SetX(value);
}
void Element::SetY(const int & value)
{
	data->position.SetY(value);
}
void Element::SetOrder(const int & value)
{
	data->node->setLocalZOrder(value);
}