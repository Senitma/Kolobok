#pragma once

// Координаты элемента
struct Axes
{
public:
	// Инициализация переменных
	Axes() : Axes(0, 0) {};
	// Инициализация переменных
	Axes(const int & x, const int & y) { SetX(x); SetY(y); };

	// Получить положение по оси X
	int GetX() const { return x; };
	// Получить положение по оси Y
	int GetY() const { return y; };
	// Изменить положение по оси X
	void SetX(const int & value) { x = value; };
	// Изменить положение по оси Y
	void SetY(const int & value) { y = value; };
protected:
	// Положение по оси X
	int x;
	// Положение по оси Y
	int y;
};