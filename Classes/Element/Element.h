#pragma once

#include "cocos2d.h"
#include "Field\FieldPoint.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\BaseAxes.h"
#include "vector"

// Базовый класс всех элементов
class Element : public cocos2d::Ref
{
public:
	// Получить имя
	ElementNameType GetName() { return name; }
	// Получить тип
	ClassType GetType() { return type; }
	// Получить сторону поворота
	SideType GetSide() { return side; }

	// Получить координату по оси X
	int GetX() { return currentPoint.GetX(); }
	// Получить координату по оси Y
	int GetY() { return currentPoint.GetY(); }
	// Получить координаты
	BaseAxes GetAxes() { return currentPoint; };

	// Добавить точку для патрулирования
	void AddPoint(int x, int y);
	// Получить точку для патрулирования
	BaseAxes GetPoint(int index) { return points.at(index); };
	// Получить количество точек для патрулирования
	int GetPointLength() { return this->points.size(); };

	// Уничтожить элемент
	virtual void Destroy() {};
protected:
	// Инициализация переменных
	Element() { currentPoint = BaseAxes(0, 0); };
	// Инициализация переменных
	Element(cocos2d::Node * node, ElementNameType name, ClassType type);
	// Сторона поворта
	SideType side;
	// Положение элемента
	BaseAxes currentPoint;
	// Узел для прорисовки
	cocos2d::Node * node;
private:
	// Имя элемента
	ElementNameType name;
	// Тип элемента
	ClassType type;

	// Точки для патрулирования
	std::vector <BaseAxes> points;
};
