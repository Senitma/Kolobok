#pragma once

#include "Option\ISOption.h"

// Перечисление возможных направлений
enum SideType;

// Опция создания элемента
class OptionForCreate : public ISOption
{
public:
	// Инициализация переменных
	OptionForCreate(Element & parent);

	// Получить имя создаваемого элемента
	ElementNameType GetName() const { return nodeName; }
	// Задать имя создаваемого элемента
	void SetName(ElementNameType value) { nodeName = value; }
	// Получить направление элемента
	SideType GetSide() const { return side; }
	// Измениь направление элемента
	void SetSide(const SideType & value) { side = value; }

	// Получить смещение по оси X
	int GetOffsetX() const { return offsetX; }
	// Задать смещение по оси X
	void SetOffsetX(const int & value) { offsetX = value; }
	// Получить смещение по оси Y
	int GetOffsetY() const { return offsetY; };
	// Задать смещение по оси Y
	void SetOffsetY(const int & value) { offsetY = value; }
	// Получить учитывание поворота
	bool GetRotate() const { return isRotate; };
	//Задать учитывание поворота
	void SetRotate(const bool & value) { isRotate = value; }

	// Создание элемента
	void Create();
protected:
	// Имя создаваемого элемента
	ElementNameType nodeName;
	// Направление элемента
	SideType side;

	// Смещение пр оси X
	int offsetX;
	// Смещение по оси Y
	int offsetY;
	// Переключатель учитывания поворота
	bool isRotate;
};