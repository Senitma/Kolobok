#pragma once

// Ссылка на данные вершины
struct RefVertex
{
	// Инициализация переменных
	RefVertex(const int & x, const int & y, const int & counter)
	{
		this->x = x; 
		this->y = y; 
		this->counter = counter;
	}

	// Положение по оси X
	int x;
	// Положение по оси Y
	int y;
	// Счетчик
	int counter;
};
// Сравнение двух ссылок
bool operator<(const RefVertex & left, const RefVertex & right) { return left.counter > right.counter; }