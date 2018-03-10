#pragma once

#include "cocos2d.h"
#include "ElementInfo.h"

// Интерфейс интервала
class ISInterval;

// Расширенный класс элемента
class Element : ElementInfo
{
public:
	// Инициализация переменных
	Element(cocos2d::Node * node, ElementNameType name, ClassType type);

	// Изменить направление
	void SetSide(const SideType & value);
	// Изменить координаты по оси X
	void SetX(const int & value);
	// Изменить координаты по оси Y
	void SetY(const int & value);
	// Изменить координаты
	void SetAxes(const int & x, const int & y);

	// Получить смещение слева
	int GetLeft() const;
	// Получить смещение сверху
	int GetTop() const;
	// Изменить смещение
	void SetPosition(const int & x, const int & y);
	// Получить угол вращения
	int GetRotation() const;
	// Измениь угол вращения
	void SetRotation(const int & value);

	// Добавить точку для патрулирования
	void AddPoint(const int & x, const int & y);
	// Получить точку для патрулирования
	BaseAxes GetPoint(const int & index);
	// Получить количество точек для патрулирования
	int GetPointLength() const;

	// Добавить опцию
	void AddOption(ISInterval * option);

	// Сравнить элементы
	bool operator== (const Element & value);
	// Сравнить элементы
	bool operator!= (const Element & value);
private:
	// Удаление конструктора по умолчанию
	Element() = delete;
};