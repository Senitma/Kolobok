#pragma once

#include "cocos2d.h"
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
	ElementNameType GetName() const { return name; }
	// Получить тип
	ClassType GetType() const { return type; }
	// Получить сторону поворота
	SideType GetSide() const { return side; }

	// Получить координату по оси X
	int GetX() const { return points.at(0).GetX(); }
	// Получить координату по оси Y
	int GetY() const { return points.at(0).GetY(); }
	// Получить координаты
	BaseAxes GetAxes() const { return points.at(0); };

	// Добавить точку для патрулирования
	void AddPoint(const int & x,const int & y);
	// Получить точку для патрулирования
	BaseAxes GetPoint(const int & index) { return points.at(index + 1); };
	// Получить количество точек для патрулирования
	int GetPointLength() const { return this->points.size() - 1; };

	// Уничтожить элемент
	virtual void Destroy() {};
protected:
	// Сторона поворта
	SideType side;
	// Узел для прорисовки
	cocos2d::Node * node;

	// Инициализация переменных
	Element(cocos2d::Node * node, const ElementNameType & name, const ClassType & type);

	// Изменить координаты по оси X
	void SetX(const int & value) { points.at(0).SetX(value); };
	// Изменить координаты по оси Y
	void SetY(const int & value) { points.at(0).SetY(value); };
private:
	// Имя элемента
	ElementNameType name;
	// Тип элемента
	ClassType type;

	// Точки для патрулирования
	std::vector<BaseAxes> points;
};
