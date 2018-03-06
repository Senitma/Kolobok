#pragma once

#include "Axes.h"

// Класс координат с идентификатором
class TagAxes : public Axes
{
public:
	// Инициализация переменных
	TagAxes() : TagAxes(0, 0, 0) {};
	// Инициализация переменных
	TagAxes(const int &x, const int &y) : TagAxes(x, y, 0) {};
	// Инициализация переменных
	TagAxes(const int &x, const int &y, const int &tag) : Axes(x, y) { SetTag(tag); };
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