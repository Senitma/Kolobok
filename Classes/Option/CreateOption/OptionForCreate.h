#pragma once

#include "Headers.h"
#include "..\Option\BaseClass\ISOption.h"

// Опция создания элемента
class OptionForCreate : public ISOption
{
public:
	// Получить имя создаваемого элемента
	ElementNameType GetName() { return nodeName; };
	// Задать имя создаваемого элемента
	void SetName(ElementNameType value) { nodeName = value; };
	// Получить смещение по оси X
	int GetOffsetX() { return offsetX; };
	// Задать смещение по оси X
	void SetOffsetX(int value) { offsetX = value; };
	// Получить смещение по оси Y
	int GetOffsetY() { return offsetY; };
	// Задать смещение по оси Y
	void SetOffsetY(int value) { offsetY = value; };
	// Получить учитывание поворота
	bool GetRotate() { return isRotate; };
	//Задать учитывание поворота
	void SetRotate(bool value) { isRotate = value; };

	// Создание элемента
	void Create();

	// Задать родителя опции
	virtual void SetParent(AdvancedElement * value) override { parent = value; };
protected:
	// Имя создаваемого элемента
	ElementNameType nodeName;
	// Смещение пр оси X
	int offsetX;
	// Смещение по оси Y
	int offsetY;
	// Переключатель учитывания поворота
	bool isRotate;
};