#pragma once

#include "Axes.h"

// Класс вершины
class Vertex : public Axes
{
public:
	// Значение клетки с блоком
	static const int BLOCKINDEX = -3;
	// Значение клетки финиша
	static const int FINISHINDEX = -2;
	// Значение пустой клетки
	static const int EMPTYINDEX = -1;
	// Значение клетки старта 
	static const int STARTINDEX = 0;

	// Инициализация переменных
	Vertex() : Vertex(0, 0, 0) {}
	// Инициализация переменных
	Vertex(const int & x, const int & y) : Vertex(x, y, 0) {}
	// Инициализация переменных
	Vertex(const int & x, const int & y, const int & pathCounter) : Axes(x, y) { this->pathCounter = pathCounter; }
	// Инициализация переменных
	Vertex(const Axes & value) : Vertex(value.GetX(), value.GetY(), 0) {}

	// Получить счетчик пути
	int GetPathCounter() const { return pathCounter; };
	// Изменить счетчик пути
	void SetPathCounter(const int & value) { pathCounter = value; };

	// Присваивание нового значения
	Vertex operator=(const Axes & value) const { return Vertex(value); };
	// Сравнение двух координат
	bool operator==(const Vertex & value) const { return ((x == value.GetX()) && (y == value.GetY() && (pathCounter == value.GetPathCounter()))); };
	// Сравнение двух координат
	bool operator!=(const Vertex & value) const { return ((x != value.GetX()) || (y != value.GetY() || (pathCounter != value.GetPathCounter()))); };
private:
	// Счетчик пути
	int pathCounter;
};