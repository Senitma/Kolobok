#pragma once

#include "queue"

#include "ElementAnimation.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\Axes.h"

#include "cocos2d.h"
#include "2d\CCNode.h"
#include "cocostudio\ActionTimeline\CCActionTimeline.h"

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
	// Анимация
	ElementAnimation animation;

	// Положение элемента
	Axes position;
	// Точки для патрулирования
	std::queue<Axes> patrolPoints;

	// Статус элемента
	bool destroyStatus;
	// Статус узла для прорисовки
	bool destroyNodeStatus;
};