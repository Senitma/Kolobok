#pragma once

#include "Axes.h"

// Класс координат с идентификатором
class TagAxes : public Axes
{
public:
	// Инициализация переменных
	TagAxes() : TagAxes(0, 0, 0) {};
	// Инициализация переменных
	TagAxes(const int & x, const int & y) : TagAxes(x, y, 0) {};
	// Инициализация переменных
	TagAxes(const int & x, const int & y, const int & tag) : Axes(x, y) { SetTag(tag); };
	// Инициализация переменных
	TagAxes(const Axes & value) : TagAxes(value.GetX(), value.GetY(), 0) {};

	// Получить идентификатор
	int GetTag() const { return tag; };
	// Изменить идентификатор
	void SetTag(int value) { tag = value; };

	// Присваивание нового значения
	TagAxes operator=(const Axes & value) { return TagAxes(value); };
	// Сравнение двух координат
	bool operator==(const TagAxes & value) const { return ((x == value.GetX()) && (y == value.GetY() && (tag == value.GetTag()))); };
	// Сравнение двух координат
	bool operator!=(const TagAxes & value) const { return ((x != value.GetX()) || (y != value.GetY() || (tag != value.GetTag()))); };
private:
	// Идентификатор
	int tag;
};