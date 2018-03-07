#pragma once

#include "BaseAxes.h"

// Класс координат с идентификатором
class TagAxes : public BaseAxes
{
public:
	// Инициализация переменных
	TagAxes() : TagAxes(0, 0, 0) {};
	// Инициализация переменных
	TagAxes(const int &x, const int &y) : TagAxes(x, y, 0) {};
	// Инициализация переменных
	TagAxes(const int &x, const int &y, const int &tag) : BaseAxes(x, y) { SetTag(tag); };
	// Инициализация переменных
	TagAxes(BaseAxes &value) { operator=(value); };

	// Получить идентификатор
	int GetTag() const { return tag; };
	// Изменить идентификатор
	void SetTag(int value) { tag = value; };
	// Получить предыдущее положение по оси X
	int GetPrevX() const { return prevX; };
	// Получить предыдущее положение по оси Y
	int GetPrevY() const { return prevY; };
	// Изменить предыдущее положение по оси X
	void SetPrevX(const int &value) { prevX = value; };
	// Изменить предыдущее положение по оси Y
	void SetPrevY(const int &value) { prevY = value; };

	// Присваивание нового значения
	void operator=(const BaseAxes &value) { x = value.GetX(); y = value.GetY(); };
	// Сравнение двух координат
	bool operator==(const TagAxes &value) { return ((x == value.GetX()) && (y == value.GetY() && (tag == value.GetTag()))); };
	// Сравнение двух координат
	bool operator!=(const TagAxes &value) { return ((x != value.GetX()) || (y != value.GetY() || (tag != value.GetTag()))); };
private:
	// Идентификатор
	int tag;
	// Предыдущее положение по оси X
	int prevX;
	// Предыдущее положение по оси Y
	int prevY;
};