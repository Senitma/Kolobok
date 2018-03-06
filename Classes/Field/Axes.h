#pragma once

#include "cocos2d.h"

// Класс координат
class Axes : public cocos2d::Ref
{
public:
	// Инициализация переменных
	Axes() : Axes(0, 0) {};
	// Инициализация переменных
	Axes(const int &x, const int &y) { SetX(x); SetY(y); };

	// Получить положение по оси X
	virtual int GetX() const { return x; };
	// Получить положение по оси Y
	virtual int GetY() const { return y; };
	// Изменить положение по оси X
	virtual void SetX(const int &value) { x = value; };
	// Изменить положение по оси Y
	virtual void SetY(const int &value) { y = value; };

	// Получить максимальное положение по оси X
	static int GetMaxForX() { return maxForX; };
	// Получить максимальное положение по оси Y
	static int GetMaxForY() { return maxForY; };

	// Преобразование в int
	operator int() const { return y * maxForX + x; };
	// Сравнение двух координат
	bool operator==(const Axes &value) { return ((x == value.GetX()) && (y == value.GetY())); };
	// Сравнение двух координат
	bool operator!=(const Axes &value) { return ((x != value.GetX()) || (y != value.GetY())); };
protected:
	// Положение по оси X
	int x;
	// Положение по оси Y
	int y;
	// Максимальное положение по оси X
	static int maxForX;
	// Максимальное положение по оси Y
	static int maxForY;
};