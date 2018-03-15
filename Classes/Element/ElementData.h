#pragma once

#include "queue"

#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\Axes.h"

#include "2d\CCNode.h"

// Данные элемента
struct ElementData
{
	// Персональный идентификатор
	int id;
	// Имя элемента
	ElementNameType name;
	// Тип элемента
	ClassType type;
	// Сторона направления
	SideType side;
	// Узел для прорисовки
	cocos2d::Node * node;
	// Положение элемента
	Axes position;
	// Точки для патрулирования
	std::queue<Axes> patrolPoints;

	// Статус элемента
	bool destroyStatus;
	// Статус узла для прорисовки
	bool destroyNodeStatus;
};