#pragma once

#include "Vertex.h"

// Перечеслинеи возможных направлений
enum SideType;
// Вершина
class Vertex;

// Ребро
class Edge
{
public:
	// Инициализация переменных
	Edge() : enable(false) {}

	// Получить статус второй вершины
	bool GetEnable() const { return enable; }

	// Получить положение по оси X
	int GetX() const;
	// Получить положение по оси Y
	int GetY() const;
	// Получить индекс в массиве
	int GetIndex() const;
	// Получить счетчик
	int GetCounter() const;
	// Изменить счетчик
	void SetCounter(const int & value);

	// Получить счетчик поворота
	int GetSideCounter() const;
	// Изменить счетчик поворота
	void SetSideCounter(const int & value);
	// Получить вес
	int GetWeight() const;
	// Изменить вес
	void SetWeight(const int & value);
	// Получить направление
	SideType GetSide();
	// Изменить направление
	void SetSide(const SideType & value);

	// Получить главное родительское ребро
	Edge & GetMainPrevEdge();
	// Получить главное родительское ребро
	Edge & GetAddPrevEdge();

	// Получить левое ребро
	Edge & GetLeftEdge();
	// Получить верхнее ребро
	Edge & GetUpEdge();
	// Получить правое ребро
	Edge & GetRightEdge();
	// Получить нижнее ребро
	Edge & GetDownEdge();

	// Получить ссылку на вторую вершину
	Vertex & GetVertex() const { return *vertex; }
	// Изменить ссылку на вторую вершину
	void SetVertex(Vertex & value) { vertex = &value; enable = true; }
private:
	// Статус вершины
	bool enable;
	// Ссылка на вершину
	Vertex * vertex;
};