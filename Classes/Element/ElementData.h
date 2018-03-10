#pragma once

#include "cocos2d.h"

#include "ElementNameType.h"
#include "ClassType.h"
#include "SideType.h"
#include "Field\BaseAxes.h"
#include "Option\BaseClass\ISInterval.h"

// Набор данных для элемента
class ElementData
{
public:
	// Имя элемента
	ElementNameType name;
	// Тип элемента
	ClassType type;
	// Сторона поворота
	SideType side;
	// Координаты елемента
	BaseAxes position;

	// Узел для прорисовки
	cocos2d::Node * node;
	// Координаты для патруля
	std::vector<BaseAxes> patrolPoints;
	// Набор опций
	std::list<ISInterval *> options;

	// Получить состояние объекта
	bool GetDestroyStatus() const { return isDestroy; };
	// Удаление данных
	void Destroy();
	// Удаление данных
	ElementData() { Destroy(); };
private:
	// Защита от повторной очистки
	bool isDestroy;
};