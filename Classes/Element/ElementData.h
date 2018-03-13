#pragma once

#include "cocos2d.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\Axes.h"

// Данные элемента
struct ElementData
{
	// Имя элемента
	ElementNameType name;
	// Тип элемента
	ClassType type;
	// Сторона поворта
	SideType side;
	// Узел для прорисовки
	cocos2d::Node * node;
	// Положение элемента
	Axes position;
	// Точки для патрулирования
	std::vector<Axes> patrolPoints;

	// Статус элемента
	bool destroyStatus;
};