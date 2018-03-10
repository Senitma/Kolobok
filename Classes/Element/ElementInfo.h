#pragma once

// Перечисление возможных имен
enum class ElementNameType;
// Перечисление возможных типов
enum class ClassType;
// Перечеслиение возможных направлений
enum class SideType;
// Набор данных для элемента
class ElementData;
// Набор координат
class BaseAxes;

// Информация о элементе
class ElementInfo
{
public:
	// Получить имя элемента
	ElementNameType GetName() const;
	// Получить тип элемента
	ClassType GetType() const;
	// Получить направление элемента
	SideType GetSide() const;
	// Получить положение по оси X
	int GetX() const;
	// Получить положение по оси Y
	int GetY() const;
	// Получить координаты элемента
	BaseAxes getAxes() const;

	// Удаление данных
	void Destroy();

	// Сравнить элементы
	bool operator== (const ElementInfo & value);
	// Сравнить элементы
	bool operator!= (const ElementInfo & value);
	// Удаление данных
	virtual ~ElementInfo() { Destroy(); };
protected:
	// Набор данных для элемента
	ElementData * data;
};