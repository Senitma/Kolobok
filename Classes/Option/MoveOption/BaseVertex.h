#pragma once

// Основные данные вершины
struct BaseVertex
{
public:
	// Инициализация переменных
	BaseVertex(const int & x, const int & y) : BaseVertex(x, y, 0) {}
	// Инициализация переменных
	BaseVertex(const int & x, const int & y, const int & counter)
	{
		this->x = x;
		this->y = y;
		this->counter = counter;

		index = GetIndex(x, y);
	}

	// Получить положение по оси X
	int GetX() const { return x; }
	// Получить положение по оси Y
	int GetY() const { return y; }
	// Получить индекс в массиве
	int GetIndex() const { return index; }
	// Получить счетчик
	int GetCounter() const { return counter; }
	// Изменит счетчик
	void SetCounter(const int & value) { counter = value; }

	// Получить индекс в массиве
	static int GetIndex(const int & x, const int & y) { return y * maxX + x; }
	// Изменить максимальные значения
	static void SetMaxX(const int & value) { maxX = value; }
private:
	// Счетчик
	int counter;

	// Положение по оси X
	int x;
	// Положение по оси Y
	int y;
	// Индекс в массиве
	int index;

	// Максимальное положение по оси X
	static int maxX;
};