#pragma once

#include "Axes.h"

// Класс координат с идентификатором
class TagAxes : Axes
{
public:
	// Инициализация переменных
	TagAxes() {};
	// Инициализация переменных
	TagAxes(Axes &value) { operator=(value); };
	// Получить идентификатор
	virtual int GetTag() const { return tag; };
	// Изменить идентификатор
	virtual void SetTag(int value) { tag = value; };

	// Присваивание нового значения
	void operator=(const Axes &value) { x = value.GetX(); y = value.GetY(); };
	// Сравнение двух координат
	bool operator==(const TagAxes &value) { return ((x == value.GetX()) && (y == value.GetY() && (tag == value.GetTag()))); };
	// Сравнение двух координат
	bool operator!=(const TagAxes &value) { return ((x != value.GetX()) || (y != value.GetY() || (tag != value.GetTag()))); };
protected:
	// Идентификатор
	int tag;
};