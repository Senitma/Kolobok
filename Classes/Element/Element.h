#pragma once

#include "cocos2d.h"

// Данные элемента
class ElementData;
// Перечисление возможных имен
enum class ElementNameType;
// Перечисление возможных типов
enum ClassType;
// Перечисление возможных направлений
enum class SideType;
// Координаты элемента
class BaseAxes;

// Класс управления элементом
class Element
{
public:
	// Инициализация переменных
	Element(cocos2d::Node * node, ElementNameType name, ClassType type);
	// Копирование элемента
	Element(const Element&);

	// Получить имя
	ElementNameType GetName() const;
	// Получить тип
	ClassType GetType() const;
	// Получить сторону поворота
	SideType GetSide() const;
	// Изменить направление
	void SetSide(const SideType & value);

	// Получить координату по оси X
	int GetX() const;
	// Получить координату по оси Y
	int GetY() const;
	// Получить координаты
	BaseAxes GetAxes() const;
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
	void SetPosition(const int x, const int y);
	// Получить угол вращения
	int GetRotation() const;
	// Измениь угол вращения
	void SetRotation(const int & value);
	// Получить статус элемента
	bool GetDestroyStatus() const;
	// Изменить статус элемента
	void SetDestroyStatus(const bool & value);

	// Добавить точку для патрулирования
	void AddPoint(const int & x, const int & y);
	// Получить точку для патрулирования
	BaseAxes GetPoint(const int & index) const;
	// Получить количество точек для патрулирования
	int GetPointLength() const;

	// Копирование элемента
	Element operator= (const Element & value) const;
	// Сравнение двух координат
	bool operator== (const Element & value) const;
	// Сравнение двух координат
	bool operator!= (const Element & value) const;

	// Удаление данных
	~Element();
private:
	// Данные элемента
	std::shared_ptr<ElementData> data;

	// Удаление конструктора по умолчанию
	Element() = delete;
};