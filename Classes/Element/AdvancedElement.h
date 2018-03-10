#pragma once

#include "Option\BaseClass\ISInterval.h"
#include "cocos2d.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\BaseAxes.h"

// Класс управления элементом
class AdvancedElement
{
public:
	// Инициализация переменных
	AdvancedElement(cocos2d::Node * node, ElementNameType name, ClassType type);

	// Получить имя
	ElementNameType GetName() const { return name; }
	// Получить тип
	ClassType GetType() const { return type; }
	// Получить сторону поворота
	SideType GetSide() const { return side; }
	// Изменить направление
	void SetSide(const SideType & value);

	// Получить координату по оси X
	int GetX() const { return points.at(0).GetX(); }
	// Получить координату по оси Y
	int GetY() const { return points.at(0).GetY(); }
	// Получить координаты
	BaseAxes GetAxes() const { return points.at(0); };
	// Изменить координаты по оси X
	void SetX(const int & value) { points.at(0).SetX(value);; };
	// Изменить координаты по оси Y
	void SetY(const int & value) { points.at(0).SetY(value); };;
	// Изменить координаты
	void SetAxes(const int & x, const int & y);

	// Получить смещение слева
	int GetLeft();
	// Получить смещение сверху
	int GetTop();
	// Изменить смещение
	void SetPosition(cocos2d::Vec2 value);
	// Получить угол вращения
	int GetRotation();
	// Измениь угол вращения
	void SetRotation(int value);

	// Добавить точку для патрулирования
	void AddPoint(const int & x, const int & y) { this->points.push_back(BaseAxes(x, y)); };
	// Получить точку для патрулирования
	BaseAxes GetPoint(const int & index) { return points.at(index + 1); };
	// Получить количество точек для патрулирования
	int GetPointLength() const { return this->points.size() - 1; };
	// Добавить опцию
	void AddOption(ISInterval * option) { items.pushBack(option); };
	// Уничтожить элемент
	void Destroy();

	// Сравнение двух координат
	bool operator== (const AdvancedElement & value) const { return node == value.node; };
	// Сравнение двух координат
	bool operator!= (const AdvancedElement & value) const { return node != value.node; };
private:
	// Имя элемента
	ElementNameType name;
	// Тип элемента
	ClassType type;
	// Сторона поворта
	SideType side;
	// Узел для прорисовки
	cocos2d::Node * node;
	// Точки для патрулирования
	std::vector<BaseAxes> points;

	// Защита от повторной очистки
	bool isDestroy;
	// Набор опций
	cocos2d::Vector<ISInterval *> items;

	// Удаление конструктора по умолчанию
	//AdvancedElement() = delete;
};