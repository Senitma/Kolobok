#pragma once

#include "cocos2d.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\BaseAxes.h"

// Данные элемента
struct ElementData
{
public:
	// Имя элемента
	ElementNameType name;
	// Тип элемента
	ClassType type;
	// Сторона поворта
	SideType side;
	// Узел для прорисовки
	cocos2d::Node * node;
	// Положение элемента
	BaseAxes position;
	// Точки для патрулирования
	std::vector<BaseAxes> patrolPoints;

	// Статус элемента
	bool destroyStatus;
};